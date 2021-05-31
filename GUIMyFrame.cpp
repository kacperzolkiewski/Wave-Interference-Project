#include "GUIMyFrame.h"
#include "CustomDialog.h"
#include <wx/popupwin.h>

GUIMyFrame::GUIMyFrame(wxWindow* parent)
	:
	MyFrame2(parent), MyDC_client(m_panel2)
{
	wxInitAllImageHandlers();

	wxSize XY = m_panel2->GetSize();
	
	//wielkosc kratek w siatce
	int x_max = (XY.x -150);
	int y_max = (XY.y - 150);
	
	_points_in_x = XY.x / 8;
	_points_in_y = XY.y / 8;
	
	_point_scale_x = x_max / static_cast<double>(_points_in_x);
	_point_scale_y = y_max / static_cast<double>(_points_in_y);
	
	for (unsigned i = 0; i < _points_in_x; ++i) {

		_points.push_back(std::vector<wxPoint>());
		_draw_points.push_back(std::vector<wxPoint>());

		for (unsigned j = 0; j < _points_in_y; ++j) {
			_points[i].push_back(wxPoint(i * _point_scale_x, j * _point_scale_y));
			_draw_points[i].push_back(wxPoint(0, 0));
			_distance.push_back(std::vector<double>());
		}

	}
	

	///ustawienie siatki tak ze obrocona jest pod katem
	int x = m_sliderX->GetValue() * 6;
	int y = m_sliderY->GetValue() * 3.5;
	int z = m_sliderZ->GetValue() * 4.5;

	_transform = set_perspective() * set_scale(1.0) * set_rotation(x, y, z) * set_translation(-static_cast<double>(_points_in_x * (_point_scale_x) / 2.0), -static_cast<double>(_points_in_y * (_point_scale_y) / 2.0));

}

void GUIMyFrame::onUpdateUI(wxUpdateUIEvent& event)
{
	// TODO: Implement onUpdateUI
	if (flag) Paint();
}

void GUIMyFrame::saveToFileClick(wxCommandEvent& event)
{
	// TODO: Implement saveToFileClick
	wxFileDialog fileDialog(this, "", "", "", "PNG files (*.png)|*.png|JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	image = buffer.ConvertToImage();

	if (fileDialog.ShowModal() == wxID_CANCEL) return;

	image.AddHandler(new wxJPEGHandler);
	image.AddHandler(new wxPNGHandler);
	image.SaveFile(fileDialog.GetPath());
}

void GUIMyFrame::on_addSource1Click(wxCommandEvent& event)
{

	MyDialog* dialog = new MyDialog();
	dialog->Show(true);
	int jmax = 0;

	if (dialog->running()) {
		how_much++;
		for (unsigned i = 0; i < _points.size(); ++i) {
			jmax = _points[i].size();
			for (unsigned j = 0; j < _points[i].size(); ++j) {
				_distance[i * jmax + j].push_back(src_distance(_points[i][j].x, _points[i][j].y, dialog->get_x(), dialog->get_y()));
			}
		}
		_amplitude.push_back(dialog->get_amplitude());
		_frequency.push_back(dialog->get_frequency());
		flag = false;
	}
}

void GUIMyFrame::on_addSource2Click(wxCommandEvent& event)
{
	// TODO: Implement on_addSource2Click
}

void GUIMyFrame::onScrollX(wxScrollEvent& event)
{
	// TODO: Implement onScrollX


	int x = m_sliderX->GetValue() * 6;
	int y = m_sliderY->GetValue() * 3.5;
	int z = m_sliderZ->GetValue() * 4.5;
	
	_transform = set_perspective() * set_scale(1.0) * set_rotation(x, y, z) * set_translation(-static_cast<double>(_points_in_x * (_point_scale_x) / 2.0), -static_cast<double>(_points_in_y * (_point_scale_y) / 2.0));
	Paint();
}

void GUIMyFrame::onScrollY(wxScrollEvent& event)
{
	// TODO: Implement onScrollY


	int x = m_sliderX->GetValue() * 6;
	int y = m_sliderY->GetValue() * 3.5;
	int z = m_sliderZ->GetValue() * 4.5;

	_transform = set_perspective() * set_scale(1.0) * set_rotation(x, y, z) * set_translation(-static_cast<double>(_points_in_x * (_point_scale_x) / 2.0), -static_cast<double>(_points_in_y * (_point_scale_y) / 2.0));
	Paint();
}

void GUIMyFrame::onScrollZ(wxScrollEvent& event)
{
	// TODO: Implement onScrollZ

	
	int x = m_sliderX->GetValue() * 6;
	int y = m_sliderY->GetValue() * 3.5;
	int z = m_sliderZ->GetValue() * 4.5;

	_transform = set_perspective() * set_scale(1.0) * set_rotation(x, y, z) * set_translation(-static_cast<double>(_points_in_x * (_point_scale_x) / 2.0), -static_cast<double>(_points_in_y * (_point_scale_y) / 2.0));
	Paint();
}

void GUIMyFrame::nextClick(wxCommandEvent& event)
{
	// TODO: Implement nextClick
}

void GUIMyFrame::prevClick(wxCommandEvent& event)
{
	// TODO: Implement prevClick
}

void GUIMyFrame::copyClick(wxCommandEvent& event)
{
	// TODO: Implement copyClick
	if (wxTheClipboard->Open())
	{
		wxTheClipboard->SetData(new wxBitmapDataObject(buffer));
		wxTheClipboard->Flush();
		wxTheClipboard->Close();
	}
}

void GUIMyFrame::startClick(wxCommandEvent& event)
{
	// TODO: Implement startClick
	
}

void GUIMyFrame::resetClick(wxCommandEvent& event)
{
	// TODO: Implement resetClick
	
	m_sliderX->SetValue(m_sliderX->GetMax() / 2);
	m_sliderY->SetValue(m_sliderY->GetMax() / 2);
	m_sliderZ->SetValue(m_sliderZ->GetMax() / 2);
	_transform = set_perspective() * set_scale(1.0) * set_rotation(m_sliderX->GetValue() * 6, m_sliderY->GetValue() * 3.5, m_sliderZ->GetValue() * 4.5) * set_translation(-static_cast<double>(_points_in_x * (_point_scale_x) / 2.0), -static_cast<double>(_points_in_y * (_point_scale_y) / 2.0));

}


double GUIMyFrame::src_distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void GUIMyFrame::Paint() {

	int k = 0;
	int jmax = 0;
	std::vector<std::vector<myVector>> transform_vector;
#pragma omp parallel for
	for (unsigned i = 0; i < _points_in_x; ++i) {
		transform_vector.push_back(std::vector<myVector>());
		for (unsigned j = 0; j < _points_in_y; ++j)
		{
			transform_vector[i].push_back(myVector(_points[i][j].x, _points[i][j].y));

		}
	}

#pragma omp parallel for
	for (unsigned i = 0; i < _points.size(); ++i) {
		jmax = _points[i].size();
		for (unsigned j = 0; j < _points[i].size(); ++j) {
			transform_vector[i][j][2] = 0;
			for (unsigned l = 0; l < how_much; ++l) {
				if (_amplitude.size() > 0)
					transform_vector[i][j][2] += _amplitude[l] * 10 * sin(0.1 * seconds - _frequency[l] * 0.01 * _distance[i * jmax + j][l]);
			}
		}
	}

#pragma omp parallel for
	for (unsigned i = 0; i < _points_in_x; ++i) {
		for (unsigned j = 0; j < _points_in_y; ++j)
		{
			transform_vector[i][j] = (_transform * transform_vector[i][j]);
			for (int k = 0; k < 3; ++k)
				transform_vector[i][j][k] /= transform_vector[i][j][3];
			_draw_points[i][j].x = transform_vector[i][j][0];
			_draw_points[i][j].y = transform_vector[i][j][1];
		}
	}

	buffer = wxBitmap(m_panel2->GetSize().x, m_panel2->GetSize().y);
	wxBufferedDC MyDC(&MyDC_client, buffer);
	MyDC.SetBackground(*wxWHITE_BRUSH);
	MyDC.Clear();

	MyDC.SetPen(wxPen(*wxBLACK));
	wxPoint* tab;
	std::vector<wxPoint> tmp;
#pragma omp parallel for
	for (unsigned i = 0; i < _points_in_x; ++i)
	{
		for (unsigned j = 0; j < _points_in_y - 1; ++j)
		{
			tmp.push_back(_draw_points[i][j]);
			if (i + 1 < _points_in_x)
				tmp.push_back(_draw_points[i + 1][j]);
			if (i - 1 > -1)
				tmp.push_back(_draw_points[i - 1][j]);
			if (i - 1 > -1 && j - 1 > -1)
				tmp.push_back(_draw_points[i - 1][j - 1]);
			tmp.push_back(_draw_points[i][j]);
			if (j + 1 < _points_in_y)
				tmp.push_back(_draw_points[i][j + 1]);
			if (i + 1 < _points_in_x && j + 1 < _points_in_y)
				tmp.push_back(_draw_points[i + 1][j + 1]);

		}
	}

	tmp.push_back(_draw_points[_points_in_x - 1][_points_in_y - 1]);
	tab = tmp.data();
	int size = tmp.size();
	wxSize XY = m_panel2->GetSize();

	//tu sie przesuwa w prawo i w lewo cala siaatke
	MyDC.DrawLines(size, tab, 320, 220);
}


void GUIMyFrame::Draw() {
	//Nie wiem czy potrzebne

}