#ifndef __MEDUSA_FRAME__
#define __MEDUSA_FRAME__

#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/listctrl.h>

#include <medusa/medusa.hpp>
#include <medusa/address.hpp>
#include <medusa/label.hpp>

#include "disassembly_view_control.hpp"

class MedusaFrame : public wxFrame
{
public:
  enum Id
  {
    wxID_DB_LOAD = wxID_HIGHEST,
    wxID_DISASM,
    wxID_LABEL,
    wxID_LOG,
    wxID_VIEW_DISASM,
    wxID_VIEW_LABEL,
    wxID_VIEW_LOG
  };

  MedusaFrame(wxWindow* pParent, wxSize const& rSize);
  ~MedusaFrame(void);

  void AddLogMessage(wxString const& rMsg);
  void AddDisassemblyLine(wxString const& rLine);
  void AddLabel(medusa::Address const& rAddr, medusa::Label const& rLbl);

protected:
  DECLARE_EVENT_TABLE()
  void OnOpen(wxCommandEvent& rEvt);
  void OnLoad(wxCommandEvent& rEvt);
  void OnSave(wxCommandEvent& rEvt);
  void OnClose(wxCommandEvent& rEvt);
  void OnAbout(wxCommandEvent& rEvt);
  void OnExit(wxCommandEvent& rEvt);

  void OnViewDisasm(wxCommandEvent& rEvt);
  void OnViewLabel(wxCommandEvent& rEvt);
  void OnViewLog(wxCommandEvent& rEvt);

  void OnLabelActivated(wxListEvent& rEvt);

  void OnDisasmMouseRightUp(wxMouseEvent& rEvt);
  void OnDisasmContextMenu(wxContextMenuEvent& rEvt);

  void DoDisasmContextMenu(wxPoint Point);

private:
  DisassemblyTextCtrl* CreateDisassemblyTextCtrl(void);
  wxTextCtrl*          CreateLogTextCtrl(void);
  wxListCtrl*          CreateLabelListCtrl(void);

  wxAuiNotebook        m_AuiNoteBook;

  DisassemblyTextCtrl* m_pDisasmTextCtrl;
  wxTextCtrl*          m_pLogTextCtrl;
  wxListCtrl*          m_pLabelListCtrl;

  medusa::Medusa       m_Core;
};

#endif // !__MEDUSA_FRAME__