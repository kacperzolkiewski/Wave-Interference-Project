#include "GUIMyFrame.h"



GUIMyFrame::GUIMyFrame(wxWindow* parent)
	:
	MyFrame2(parent), myClient(m_panel2)
{
	wxInitAllImageHandlers();
	wxSize panelSize = m_panel2->GetSize();

	pointsX = panelSize.x / 8;
	pointsY = panelSize.y / 8;

	scaleX = (panelSize.x - 90) / static_cast<double>(pointsX);
	scaleY = (panelSize.y - 90) / static_cast<double>(pointsY);

	initializeVec(pointsX, pointsY, scaleX, scaleY);

	int x = m_sliderX->GetValue() * 6;
	int y = m_sliderY->GetValue() * 3.5;
	int z = m_sliderZ->GetValue() * 4.5;

	transformMatrix = setPerspective() * setScale(1.0) * setRotation(x, y, z) *
		setTranslation(-static_cast<double>(pointsX * (scaleX) / 2.0),
			-static_cast<double>(pointsY * (scaleY) / 2.0));
}

void GUIMyFrame::initializeVec(unsigned pointsX, unsigned pointsY, double scaleX, double scaleY) {

	for (unsigned i = 0; i < pointsX; ++i) {

		points.push_back(std::vector<wxPoint>());
		drawPoints.push_back(std::vector<wxPoint>());

		for (unsigned j = 0; j < pointsY; ++j) {
			points[i].push_back(wxPoint(i * scaleX, j * scaleY));
			drawPoints[i].push_back(wxPoint(0, 0));
			points1Distance.push_back(std::vector<double>());
			points2Distance.push_back(std::vector<double>());
		}

	}

}

void GUIMyFrame::onUpdateUI(wxUpdateUIEvent& event)
{
	if (flag2 && flag1) Paint();
}

void GUIMyFrame::saveToFileClick(wxCommandEvent& event)
{
	wxFileDialog fileDialog(this, "", "", "", "PNG files (*.png)|*.png|JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	
	interferenceImage = myBuffer.ConvertToImage();

	if (fileDialog.ShowModal() == wxID_CANCEL) return;

	interferenceImage.AddHandler(new wxJPEGHandler);
	interferenceImage.AddHandler(new wxPNGHandler);
	interferenceImage.SaveFile(fileDialog.GetPath());
}

void GUIMyFrame::on_addSource1Click(wxCommandEvent& event)
{
	addSource(points, points1Distance, points1Amplitude, points1Frequency, flag1);
}

void GUIMyFrame::on_addSource2Click(wxCommandEvent& event)
{
	addSource(points, points2Distance, points2Amplitude, points2Frequency, flag2);
}

void GUIMyFrame::addSource(std::vector<std::vector<wxPoint>>& points, std::vector<std::vector<double>>& pointsDistance,
	double& pointsAmplitude, double& pointsFrequency, bool& flag)
{
	clearDistance(points, pointsDistance ,pointsAmplitude, pointsFrequency);

	MyDialog* dialog = new MyDialog();
	dialog->Show(true);
	

	if (dialog->running()) {

		unsigned temp = 0;
		for (unsigned i = 0; i < points.size(); ++i) {
			temp = points[i].size();
			for (unsigned j = 0; j < points[i].size(); ++j) {
				pointsDistance[i * temp + j].push_back(measureDistance(points[i][j].x,
					points[i][j].y, dialog->getX(), dialog->getY()));
			}
		}
		pointsAmplitude = dialog->getAmplitude();
		pointsFrequency = dialog->getFrequency();
		flag = false;
	}
}

void GUIMyFrame::onScrollX(wxScrollEvent& event)
{
	scroll();
}

void GUIMyFrame::onScrollY(wxScrollEvent& event)
{
	scroll();
}

void GUIMyFrame::onScrollZ(wxScrollEvent& event)
{
	scroll();
}

void GUIMyFrame::scroll()
{
	int x = m_sliderX->GetValue() * 6;
	int y = m_sliderY->GetValue() * 3.5;
	int z = m_sliderZ->GetValue() * 4.5;

	transformMatrix = setPerspective() * setScale(1.0) * setRotation(x, y, z) *
		setTranslation(-static_cast<double>(pointsX * (scaleX) / 2.0),
			-static_cast<double>(pointsY * (scaleY) / 2.0));
	Paint();
}

void GUIMyFrame::nextClick(wxCommandEvent& event)
{
	seconds = seconds + 1;
	Paint();
}

void GUIMyFrame::prevClick(wxCommandEvent& event)
{
	seconds = seconds - 1;
	Paint();
}

void GUIMyFrame::copyClick(wxCommandEvent& event)
{
	if (wxTheClipboard->Open())
	{
		wxTheClipboard->SetData(new wxBitmapDataObject(myBuffer));
		wxTheClipboard->Flush();
		wxTheClipboard->Close();
	}
}

void GUIMyFrame::startClick(wxCommandEvent& event)
{
	if (points1Amplitude == 0 && points2Amplitude == 0) {
		wxLogMessage("You have to add source, if you want to start");
		return;
	}

	m_start->SetLabel("SIMULATING");
	flag2 = flag1 = true;

	long startTime = wxGetLocalTime();
	long actualTime = startTime;
	long timeDiffrence = 0;

	seconds = 0;
	timer.Start(100);

	while (timeDiffrence <= duration) {
		Paint();
		time += timer.GetInterval() / 100.0;
		seconds = time;

		actualTime = wxGetLocalTime();
		timeDiffrence = actualTime - startTime;
	}

	timer.Stop();
	m_start->SetLabel("START");
}

void GUIMyFrame::resetClick(wxCommandEvent& event)
{
	m_sliderX->SetValue(m_sliderX->GetMax() / 2);
	m_sliderY->SetValue(m_sliderY->GetMax() / 2);
	m_sliderZ->SetValue(m_sliderZ->GetMax() / 2);

	transformMatrix = setPerspective() * setScale(1.0) * setRotation(m_sliderX->GetValue() * 6,
		m_sliderY->GetValue() * 3.5, m_sliderZ->GetValue() * 4.5) * setTranslation(-static_cast<double>(pointsX * (scaleX) / 2.0),
			-static_cast<double>(pointsY * (scaleY) / 2.0));


	clearDistance(points, points1Distance, points1Amplitude, points1Frequency);
	clearDistance(points, points2Distance, points2Amplitude, points2Frequency);

	Paint();
}


double GUIMyFrame::measureDistance(const double x1, const  double y1, const  double x2, const  double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void GUIMyFrame::Paint()
{
	std::vector<std::vector<myVector>> transformation;

	int tempSize = 0;

#pragma omp parallel for
	for (unsigned i = 0; i < pointsX; ++i) {
		transformation.push_back(std::vector<myVector>());
		for (unsigned j = 0; j < pointsY; ++j)
		{
			transformation[i].push_back(myVector(points[i][j].x, points[i][j].y));

		}
	}

#pragma omp parallel for
	for (unsigned i = 0; i < points.size(); ++i) {

		tempSize = points[i].size();
		for (unsigned j = 0; j < points[i].size(); ++j) {

			if (points1Amplitude != 0) 
			{
				transformation[i][j][2] += points1Amplitude * 10 * sin(0.1 * seconds - points1Frequency * 0.01 * points1Distance[i * tempSize + j][0]);
			}

			if (points2Amplitude != 0) 
			{
				transformation[i][j][2] += points2Amplitude * 10 * sin(0.1 * seconds - points2Frequency * 0.01 * points2Distance[i * tempSize + j][0]);
			}
		}
	}

#pragma omp parallel for
	for (unsigned i = 0; i < pointsX; ++i) {
		for (unsigned j = 0; j < pointsY; ++j)
		{
			transformation[i][j] = (transformMatrix * transformation[i][j]);
			for (unsigned k = 0; k < 3; ++k) {
				transformation[i][j][k] /= transformation[i][j][3];

			}

			drawPoints[i][j].x = transformation[i][j][0];
			drawPoints[i][j].y = transformation[i][j][1];
		}
	}
	
	std::vector<wxPoint> tempVector;

#pragma omp parallel for
	for (unsigned i = 0; i < pointsX; ++i)
	{
		for (unsigned j = 0; j < pointsY - 1; ++j)
		{

			tempVector.push_back(drawPoints[i][j]);
			if (i + 1 < pointsX) {
				tempVector.push_back(drawPoints[i + 1][j]);
			}
			if (i - 1 > -1) {
				tempVector.push_back(drawPoints[i - 1][j]);
			}
			if (i - 1 > -1 && j - 1 > -1) {
				tempVector.push_back(drawPoints[i - 1][j - 1]);
			}
			tempVector.push_back(drawPoints[i][j]);
			if (j + 1 < pointsY) {
				tempVector.push_back(drawPoints[i][j + 1]);
			}
			if (i + 1 < pointsX && j + 1 < pointsY) {
				tempVector.push_back(drawPoints[i + 1][j + 1]);
			}

		}
	}

	myBuffer = wxBitmap(m_panel2->GetSize().x, m_panel2->GetSize().y);
	wxBufferedDC MyDC(&myClient, myBuffer);

	MyDC.SetBackground(*wxWHITE_BRUSH);
	MyDC.Clear();
	MyDC.SetPen(wxPen(*wxBLUE));

	tempVector.push_back(drawPoints[pointsX - 1][pointsY - 1]);
	
	MyDC.DrawLines(tempVector.size(), tempVector.data(), 320, 220);
}


void GUIMyFrame::clearDistance(std::vector<std::vector<wxPoint>>& points, std::vector<std::vector<double>>& pointsDistance, double& pointsAmplitude, double& pointsFrequency)
{
	for (unsigned i = 0; i < points.size(); ++i) {
		unsigned tempSize = points[i].size();
		for (unsigned j = 0; j < points[i].size(); ++j) {
			pointsDistance[i * tempSize + j].clear();
		}
	}

	pointsAmplitude = 0;
	pointsFrequency = 0;
}