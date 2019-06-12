#include "simple.h"

Simple::Simple(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{

    wxPanel *panel = new wxPanel(this, wxID_ANY);

    wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"),
                                    wxPoint(20, 20));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Simple::OnQuit));
    button->SetFocus();

    this->Centre();
}


void Simple::OnQuit(wxCommandEvent & WXUNUSED(event))
{
    Close(true);
}