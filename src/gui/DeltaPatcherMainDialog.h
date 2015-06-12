//Copyright (C) 2015 Phoenix.

//This program is free software: you can redistribute it and/or modify 
//it under the terms of the GNU General Public License as published by 
//the Free Software Foundation, version 2.0. 

//This program is distributed in the hope that it will be useful, 
//but WITHOUT ANY WARRANTY; without even the implied warranty of 
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
//GNU General Public License 2.0 for more details. 

//A copy of the GPL 2.0 should have been included with the program. 
//If not, see http://www.gnu.org/licenses/ 

//Source code and contact information can be found at 
//https://github.com/marco-calautti


#ifndef __DeltaPatcherMainDialog__
#define __DeltaPatcherMainDialog__

/**
@file
Subclass of MainDialog, which is generated by wxFormBuilder.
*/

#include "DeltaPatcherEncodePanel.h"
#include <wx/dnd.h>
#include "dpgui.h"
#include "DeltaPatcherDecodePanel.h"
#include "Logger.h"

/** Implementing MainDialog */
class DeltaPatcherMainDialog : public MainDialog, public Logger
{
protected:
	// Handlers for MainDialog events.
	void OnShowHideLog( wxCommandEvent& event );
	void OnMainDialogClose( wxCloseEvent& event );
	void OnClickAbout( wxCommandEvent& event );
	void OnOperationSelected( wxCommandEvent& event );
	//Workaround for stupid sizing bug in wxGTK
	void OnActivate( wxActivateEvent& event ) { static bool first=true; if(first){Update(); Fit(); first=false;} event.Skip(); }
public:
	/** Constructor */
	DeltaPatcherMainDialog( wxWindow* parent, const wxChar* patchName=wxEmptyString);
	
	virtual void Log(int type,const wxChar* msg);
	void ShowHideLog();
private:
	DeltaPatcherDecodePanel* decodePanel;
	DeltaPatcherEncodePanel* encodePanel;
	
	bool decodeMode;
};

#endif // __DeltaPatcherMainDialog__
