#include "GUIMyFrame.h"
#include "CustomDialog.h"
#include <wx/popupwin.h>

GUIMyFrame::GUIMyFrame(wxWindow* parent)
	:
	MyFrame2(parent), myClient(m_panel2)
{
	wxInitAllImageHandlers();

	wxSize XY = m_panel2->GetSize();

	//wielkosc kratek w siatce
	int x_max = (XY.x - 90);
	int y_max = (XY.y - 90);

	pointsX = XY.x / 6;
	pointsY = XY.y / 6;

	scaleX = x_max / static_cast<double>(pointsX);
	scaleY = y_max / static_cast<double>(pointsY);

	for (unsigned i = 0; i < pointsX; ++i) {

		points1.push_back(std::vector<wxPoint>());
		drawPoints1.push_back(std::vector<wxPoint>());

		for (unsigned j = 0; j < pointsY; ++j) {
			points1[i].push_back(wxPoint(i * scaleX, j * scaleY));
			drawPoints1[i].push_back(wxPoint(0, 0));
			points1Distance.push_back(std::vector<double>());
			points2Distance.push_back(std::vector<double>());
		}

	}


	///ustawienie siatki tak ze obrocona jest pod katem
	int x = m_sliderX->GetValue() * 6;
	int y = m_sliderY->GetValue() * 3.5;
	int z = m_sliderZ->GetValue() * 4.5;

	transformMatrix = set_perspective() * set_scale(1.0) * set_rotation(x, y, z) *
		set_translation(-static_cast<double>(pointsX * (scaleX) / 2.0),
			-static_cast<double>(pointsY * (scaleY) / 2.0));
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
	addSource(points1, points1Distance, points1Amplitude, points1Frequency, flag1, counter1);
}

void GUIMyFrame::on_addSource2Click(wxCommandEvent& event)
{
	addSource(points1, points2Distance, points2Amplitude, points2Frequency, flag2, counter2);
}

void GUIMyFrame::addSource(std::vector<std::vector<wxPoint>>& points, std::vector<std::vector<double>>& pointsDistance,
	std::vector<double>& pointsAmplitude, std::vector<double>& pointsFrequency, bool& flag, unsigned& counter)
{
	MyDialog* dialog = new MyDialog();
	dialog->Show(true);
	int max = 0;

	if (dialog->running()) {
		counter++;
		for (unsigned i = 0; i < points.size(); ++i) {
			max = points[i].size();
			for (unsigned j = 0; j < points[i].size(); ++j) {
				pointsDistance[i * max + j].push_back(measureDistance(points[i][j].x,
					points[i][j].y, dialog->getX(), dialog->getY()));
			}
		}
		pointsAmplitude.push_back(dialog->getAmplitude());
		pointsFrequency.push_back(dialog->getFrequency());
		flag = false;
	}

	wxLogMessage("Wybrane przez Ciebie parametry (x, y, amplitude, frequency) to: "
		+ wxString::Format(wxT("%f.2"), dialog->getX()) + " "
		+ wxString::Format(wxT("%f.2"), dialog->getY()) + " "
		+ wxString::Format(wxT("%f.2"), dialog->getAmplitude()) + " "
		+ wxString::Format(wxT("%f.2"), dialog->getFrequency()));
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

	transformMatrix = set_perspective() * set_scale(1.0) * set_rotation(x, y, z) *
		set_translation(-static_cast<double>(pointsX * (scaleX) / 2.0),
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
	if (points1Amplitude.size() <= 0 && points2Amplitude.size() <= 0) {
		wxLogMessage("You have to add source, if you want to start");
		return;
	}
	m_start->SetLabel("PROCESSING");
	flag1 = true;
	flag2 = true;

	int start_time = wxGetLocalTime();
	int time_now = start_time;
	seconds = 0;
	timer.Start(100);
	int time_diff = time_now - start_time;

	while (time_diff <= duration) {
		Draw();
		time_now = wxGetLocalTime();
		time_diff = time_now - start_time;
	}

	timer.Stop();
	m_start->SetLabel("START");
}

void GUIMyFrame::resetClick(wxCommandEvent& event)
{
	m_sliderX->SetValue(m_sliderX->GetMax() / 2);
	m_sliderY->SetValue(m_sliderY->GetMax() / 2);
	m_sliderZ->SetValue(m_sliderZ->GetMax() / 2);
	transformMatrix = set_perspective() * set_scale(1.0) * set_rotation(m_sliderX->GetValue() * 6,
		m_sliderY->GetValue() * 3.5, m_sliderZ->GetValue() * 4.5) * set_translation(-static_cast<double>(pointsX * (scaleX) / 2.0),
			-static_cast<double>(pointsY * (scaleY) / 2.0));


	for (unsigned i = 0; i < points1.size(); ++i) {
		int jmax = points1[i].size();
		for (unsigned j = 0; j < points1[i].size(); ++j) {
			points1Distance[i * jmax + j].clear();
			
		}
	}

	for (unsigned i = 0; i < points2.size(); ++i) {
		int jmax = points2[i].size();
		for (unsigned j = 0; j < points2[i].size(); ++j) {
			points2Distance[i * jmax + j].clear();

		}
	}
	
	counter1 = 0;
	counter2 = 0;
	points1Amplitude.clear();
	points2Amplitude.clear();
	points1Frequency.clear();
	points2Frequency.clear();
	Paint();
	seconds = 0;
}


double GUIMyFrame::measureDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void GUIMyFrame::Paint() {

	int k = 0;
	int max = 0;
	std::vector<std::vector<myVector>> transform_vector;
#pragma omp parallel for
	for (unsigned i = 0; i < pointsX; ++i) {
		transform_vector.push_back(std::vector<myVector>());
		for (unsigned j = 0; j < pointsY; ++j)
		{
			transform_vector[i].push_back(myVector(points1[i][j].x, points1[i][j].y));

		}
	}

#pragma omp parallel for
	for (unsigned i = 0; i < points1.size(); ++i) {

		max = points1[i].size();
		for (unsigned j = 0; j < points1[i].size(); ++j) {

			transform_vector[i][j][2] = 0;
			for (unsigned l = 0; l < counter1; ++l) {
				if (points1Amplitude.size() > 0) {

					transform_vector[i][j][2] += points1Amplitude[l] * 10 * sin(0.1 * seconds - points1Frequency[l] * 0.01 * points1Distance[i * max + j][l]);
					//transform_vector[i][j][2] += _amplitude_2[l] * 10 * sin(0.1 * seconds - _frequency_2[l] * 0.01 * _distance_2[i * jmax + j][l]);
				}
			}
			for (unsigned l = 0; l < counter2; ++l) {
				if (points2Amplitude.size() > 0) {

					//transform_vector[i][j][2] += _amplitude[l] * 10 * sin(0.1 * seconds - _frequency[l] * 0.01 * _distance[i * jmax + j][l]);
					transform_vector[i][j][2] += points2Amplitude[l] * 10 * sin(0.1 * seconds - points2Frequency[l] * 0.01 * points2Distance[i * max + j][l]);
				}
			}
		}
	}

#pragma omp parallel for
	for (unsigned i = 0; i < pointsX; ++i) {
		for (unsigned j = 0; j < pointsY; ++j)
		{
			transform_vector[i][j] = (transformMatrix * transform_vector[i][j]);
			for (int k = 0; k < 3; ++k) {
				transform_vector[i][j][k] /= transform_vector[i][j][3];

			}

			drawPoints1[i][j].x = transform_vector[i][j][0];
			drawPoints1[i][j].y = transform_vector[i][j][1];
		}
	}

	myBuffer = wxBitmap(m_panel2->GetSize().x, m_panel2->GetSize().y);
	wxBufferedDC MyDC(&myClient, myBuffer);
	MyDC.SetBackground(*wxWHITE_BRUSH);
	MyDC.Clear();

	MyDC.SetPen(wxPen(*wxBLUE));
	wxPoint* tab;
	std::vector<wxPoint> tmp;
#pragma omp parallel for
	for (unsigned i = 0; i < pointsX; ++i)
	{
		for (unsigned j = 0; j < pointsY - 1; ++j)
		{

			tmp.push_back(drawPoints1[i][j]);
			if (i + 1 < pointsX) {
				tmp.push_back(drawPoints1[i + 1][j]);
			}
			if (i - 1 > -1) {
				tmp.push_back(drawPoints1[i - 1][j]);
			}
			if (i - 1 > -1 && j - 1 > -1) {
				tmp.push_back(drawPoints1[i - 1][j - 1]);
			}
			tmp.push_back(drawPoints1[i][j]);
			if (j + 1 < pointsY) {
				tmp.push_back(drawPoints1[i][j + 1]);
			}
			if (i + 1 < pointsX && j + 1 < pointsY) {
				tmp.push_back(drawPoints1[i + 1][j + 1]);
			}

		}
	}

	tmp.push_back(drawPoints1[pointsX - 1][pointsY - 1]);
	tab = tmp.data();
	int size = tmp.size();
	wxSize XY = m_panel2->GetSize();

	//tu sie przesuwa w prawo i w lewo cala siaatke
	MyDC.DrawLines(size, tab, 320, 220);
}

void GUIMyFrame::Draw() {
	Paint();
	time += timer.GetInterval() / 100.;
	seconds = time;
}