#include "MainFrame.h"
#include "../utils/Helper.h"
#include <wx/sizer.h>

// Definición de IDs para los botones
const int ID_BUTTON_CLICK = 1001;
const int ID_BUTTON_CLOSE = 1002;

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(ID_BUTTON_CLICK, MainFrame::OnButtonClick)        // Primer botón
    EVT_BUTTON(ID_BUTTON_CLOSE, MainFrame::OnSecondButtonClick)  // Segundo botón (cierre)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400)) {
    wxPanel* panel = new wxPanel(this, -1);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* contentSizer = new wxBoxSizer(wxVERTICAL);

    // Título centrado
    wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, wxT("Bienvenidos desde el modulo ui"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    titleText->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD)); // Fuente más grande y negrita
    contentSizer->Add(titleText, 0, wxALL | wxALIGN_CENTER, 15);

    // Espacio entre el título y los botones
    contentSizer->AddSpacer(10);

    // Crear un sizer vertical para centrar los botones
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);
    
    // Botón principal
    wxButton* button = new wxButton(panel, ID_BUTTON_CLICK, wxT("Click me")); // Asignar un ID fijo
    button->SetBackgroundColour(*wxLIGHT_GREY);
    button->SetForegroundColour(*wxBLACK);
    buttonSizer->Add(button, 0, wxALL | wxEXPAND, 15); // Ocupa todo el ancho

    // Botón secundario (nuevo)
    wxButton* secondButton = new wxButton(panel, ID_BUTTON_CLOSE, wxT("Cerrar")); // Asignar un ID fijo
    secondButton->SetBackgroundColour(*wxLIGHT_GREY);
    secondButton->SetForegroundColour(*wxBLACK);
    buttonSizer->Add(secondButton, 0, wxALL | wxEXPAND, 15); // Ocupa todo el ancho

    // Añadir el sizer de botones al sizer de contenido
    contentSizer->Add(buttonSizer, 1, wxALIGN_CENTER | wxEXPAND); // 1 para expandir y centrar verticalmente

    // Añadir el sizer de contenido al sizer principal
    mainSizer->Add(contentSizer, 1, wxEXPAND); // Expandir el sizer de contenido para usar todo el espacio

    panel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);

    // Establecer el tamaño mínimo y ajustar el tamaño
    this->SetMinSize(wxSize(400, 200)); // Establecer el tamaño mínimo
    this->SetSize(wxSize(400, 200));     // Establecer el tamaño inicial
}

void MainFrame::OnButtonClick(wxCommandEvent& event) {
    std::string greeting = GetGreeting(); // Obtener el saludo
    wxMessageBox(greeting, wxT("Saludando"), wxOK | wxICON_INFORMATION, this); // Mostrar el mensaje
}

void MainFrame::OnSecondButtonClick(wxCommandEvent& event) {
    Close(true); // Cerrar la ventana
}
