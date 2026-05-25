#include <fx.h>
#include "res/foxres.h"

FXIcon* ico_mainicon;

FXIcon* ico_ed_copy;
FXIcon* ico_ed_cut;
FXIcon* ico_ed_delete;
FXIcon* ico_ed_findcase;
FXIcon* ico_ed_find;
FXIcon* ico_ed_findnext;
FXIcon* ico_ed_findopen;
FXIcon* ico_ed_findprev;
FXIcon* ico_ed_findwhole;
FXIcon* ico_ed_paste;
FXIcon* ico_ed_redo;
FXIcon* ico_ed_regex;
FXIcon* ico_ed_undo;
FXIcon* ico_idk;
FXIcon* ico_ins_exist;
FXIcon* ico_ins_newres;
FXIcon* ico_std_about;
FXIcon* ico_std_classwizard;
FXIcon* ico_std_findhlp;
FXIcon* ico_std_home;
FXIcon* ico_std_new;
FXIcon* ico_std_newtext;
FXIcon* ico_std_open;
FXIcon* ico_std_print;
FXIcon* ico_std_prop;
FXIcon* ico_std_saveall;
FXIcon* ico_std_save;
FXIcon* ico_std_userdef10;
FXIcon* ico_std_userdef11;
FXIcon* ico_std_userdef12;
FXIcon* ico_std_userdef13;
FXIcon* ico_std_userdef14;
FXIcon* ico_std_userdef15;
FXIcon* ico_std_userdef16;
FXIcon* ico_std_userdef1;
FXIcon* ico_std_userdef2;
FXIcon* ico_std_userdef3;
FXIcon* ico_std_userdef4;
FXIcon* ico_std_userdef5;
FXIcon* ico_std_userdef6;
FXIcon* ico_std_userdef7;
FXIcon* ico_std_userdef8;
FXIcon* ico_std_userdef9;
FXIcon* ico_std_webpage;
FXIcon* ico_view_cascade;
FXIcon* ico_view_close;
FXIcon* ico_view_fullscreen;
FXIcon* ico_view_newwin;
FXIcon* ico_view_next;
FXIcon* ico_view_prev;
FXIcon* ico_view_refresh;
FXIcon* ico_view_split;
FXIcon* ico_view_tilehor;
FXIcon* ico_view_tilever;
FXIcon* ico_view_viewdows;
FXIcon* ico_view_workspace;


class VisixWindow : public FXMainWindow {
	FXDECLARE(VisixWindow)

private:
	FXDockSite*     topdock;

	FXToolBarShell* tsmenubar;
	FXToolBarShell* tstoolbar1;

	FXMenuBar*      menubar;
	FXToolBar*      toolbar1;

	FXButton*       btn;

protected:
	VisixWindow() {}

public:
	long onCmdExample(FXObject*, FXSelector, void*);

public:
	enum {
		ID_BEFORE = FXMainWindow::ID_LAST,
		ID_EXAMPLE,
		ID_LAST
	};

public:
	VisixWindow(FXApp* a);

	virtual void create();
	virtual ~VisixWindow();
};

FXDEFMAP(VisixWindow) VisixWindowMap[] = {
	FXMAPFUNC(SEL_COMMAND,           VisixWindow::ID_EXAMPLE,  VisixWindow::onCmdExample),
};

FXIMPLEMENT(VisixWindow, FXMainWindow, VisixWindowMap, ARRAYNUMBER(VisixWindowMap));

VisixWindow::VisixWindow(FXApp *a) : FXMainWindow(a, "Visix", ico_mainicon, NULL, DECOR_ALL, 0,0,0,0) {
	topdock = new FXDockSite(this, LAYOUT_SIDE_TOP|LAYOUT_FILL_X, 0,0,0,0, 0,0,0,-1);
	
	// menubar
	tsmenubar = new FXToolBarShell(topdock, 0);
	menubar = new FXMenuBar(topdock, tsmenubar, LAYOUT_FILL_X|FRAME_RAISED, 0,0,0,0, 3,3,2,2, 0,0);

	new FXToolBarGrip(menubar, menubar, FXMenuBar::ID_TOOLBARGRIP,TOOLBARGRIP_DOUBLE);

	new FXMenuTitle(menubar, "&File");
	new FXMenuTitle(menubar, "&Edit");
	new FXMenuTitle(menubar, "&View");
	new FXMenuTitle(menubar, "&Insert");
	//new FXMenuTitle(menubar, "&Project");
	//new FXMenuTitle(menubar, "&Build");
	new FXMenuTitle(menubar, "&Tools");
	new FXMenuTitle(menubar, "&Window");
	new FXMenuTitle(menubar, "&Help");

	/* toolbar*/
	tstoolbar1 = new FXToolBarShell(topdock, 0);
	toolbar1 = new FXToolBar(topdock, tstoolbar1, LAYOUT_DOCK_NEXT|FRAME_RAISED, 0,0,0,0, 3,3,2,2, 2,2);
	new FXToolBarGrip(toolbar1, toolbar1, FXToolBar::ID_TOOLBARGRIP,TOOLBARGRIP_DOUBLE);

	new FXButton(toolbar1, "\tNew Text File\tCreates a new text file.",
			ico_std_newtext, NULL, 0, BUTTON_TOOLBAR|FRAME_RAISED);

	new FXVerticalSeparator(toolbar1);

	new FXButton(toolbar1, "\tOpen (Ctrl+O)\tOpens an existing document",
			ico_std_open, NULL, 0, BUTTON_TOOLBAR|FRAME_RAISED);
	
	new FXButton(toolbar1, "\tSave (Ctrl+S)\tSaves the document",
			ico_std_save, NULL, 0, BUTTON_TOOLBAR|FRAME_RAISED);

	new FXButton(toolbar1, "\tSave All\tSaves all the open files",
			ico_std_saveall, NULL, 0, BUTTON_TOOLBAR|FRAME_RAISED);

	new FXVerticalSeparator(toolbar1);
	
	new FXButton(toolbar1, "\tCut (Ctrl+X)"
			"\tCuts the selection and moves it to the Clipboard",
			ico_ed_cut, NULL, 0, BUTTON_TOOLBAR|FRAME_RAISED);
	
	new FXButton(toolbar1, "\tCopy (Ctrl+C)"
			"\tCopies the selection to the Clipboard",
			ico_ed_copy, NULL, 0, BUTTON_TOOLBAR|FRAME_RAISED);
	
	new FXButton(toolbar1, "\tPaste (Ctrl+V)"
			"\tInserts the Clipboard contents at the insertion point",
			ico_ed_paste, NULL, 0, BUTTON_TOOLBAR|FRAME_RAISED);



	new FXStatusBar(this, LAYOUT_FILL_X|LAYOUT_SIDE_BOTTOM|STATUSBAR_WITH_DRAGCORNER);

	FXPacker* frame = new FXPacker(this, FRAME_NORMAL|LAYOUT_FILL_X|LAYOUT_FILL_Y);
	frame->setBackColor(a->getBackColor());
}

VisixWindow::~VisixWindow() {
}


void VisixWindow::create() {
	FXMainWindow::create();
	show(PLACEMENT_SCREEN);
}

long VisixWindow::onCmdExample(FXObject*, FXSelector, void*) {
	puts("o/");
	return 1;
}

int main(int argc, char *argv[]) {
	FXApp application("Visix", "Visix");

	ico_mainicon = new FXGIFIcon(&application, resico_mainicon);

	ico_ed_copy = new FXGIFIcon(&application, resico_ed_copy);
	ico_ed_cut = new FXGIFIcon(&application, resico_ed_cut);
	ico_ed_delete = new FXGIFIcon(&application, resico_ed_delete);
	ico_ed_findcase = new FXGIFIcon(&application, resico_ed_findcase);
	ico_ed_find = new FXGIFIcon(&application, resico_ed_find);
	ico_ed_findnext = new FXGIFIcon(&application, resico_ed_findnext);
	ico_ed_findopen = new FXGIFIcon(&application, resico_ed_findopen);
	ico_ed_findprev = new FXGIFIcon(&application, resico_ed_findprev);
	ico_ed_findwhole = new FXGIFIcon(&application, resico_ed_findwhole);
	ico_ed_paste = new FXGIFIcon(&application, resico_ed_paste);
	ico_ed_redo = new FXGIFIcon(&application, resico_ed_redo);
	ico_ed_regex = new FXGIFIcon(&application, resico_ed_regex);
	ico_ed_undo = new FXGIFIcon(&application, resico_ed_undo);
	ico_idk = new FXGIFIcon(&application, resico_idk);
	ico_ins_exist = new FXGIFIcon(&application, resico_ins_exist);
	ico_ins_newres = new FXGIFIcon(&application, resico_ins_newres);
	ico_std_about = new FXGIFIcon(&application, resico_std_about);
	ico_std_classwizard = new FXGIFIcon(&application, resico_std_classwizard);
	ico_std_findhlp = new FXGIFIcon(&application, resico_std_findhlp);
	ico_std_home = new FXGIFIcon(&application, resico_std_home);
	ico_std_new = new FXGIFIcon(&application, resico_std_new);
	ico_std_newtext = new FXGIFIcon(&application, resico_std_newtext);
	ico_std_open = new FXGIFIcon(&application, resico_std_open);
	ico_std_print = new FXGIFIcon(&application, resico_std_print);
	ico_std_prop = new FXGIFIcon(&application, resico_std_prop);
	ico_std_saveall = new FXGIFIcon(&application, resico_std_saveall);
	ico_std_save = new FXGIFIcon(&application, resico_std_save);

	ico_std_userdef1 = new FXGIFIcon(&application, resico_std_userdef1);
	ico_std_userdef2 = new FXGIFIcon(&application, resico_std_userdef2);
	ico_std_userdef3 = new FXGIFIcon(&application, resico_std_userdef3);
	ico_std_userdef4 = new FXGIFIcon(&application, resico_std_userdef4);
	ico_std_userdef5 = new FXGIFIcon(&application, resico_std_userdef5);
	ico_std_userdef6 = new FXGIFIcon(&application, resico_std_userdef6);
	ico_std_userdef7 = new FXGIFIcon(&application, resico_std_userdef7);
	ico_std_userdef8 = new FXGIFIcon(&application, resico_std_userdef8);
	ico_std_userdef9 = new FXGIFIcon(&application, resico_std_userdef9);
	ico_std_userdef10 = new FXGIFIcon(&application, resico_std_userdef10);
	ico_std_userdef11 = new FXGIFIcon(&application, resico_std_userdef11);
	ico_std_userdef12 = new FXGIFIcon(&application, resico_std_userdef12);
	ico_std_userdef13 = new FXGIFIcon(&application, resico_std_userdef13);
	ico_std_userdef14 = new FXGIFIcon(&application, resico_std_userdef14);
	ico_std_userdef15 = new FXGIFIcon(&application, resico_std_userdef15);
	ico_std_userdef16 = new FXGIFIcon(&application, resico_std_userdef16);

	ico_std_webpage = new FXGIFIcon(&application, resico_std_webpage);
	ico_view_cascade = new FXGIFIcon(&application, resico_view_cascade);
	ico_view_close = new FXGIFIcon(&application, resico_view_close);
	ico_view_fullscreen = new FXGIFIcon(&application, resico_view_fullscreen);
	ico_view_newwin = new FXGIFIcon(&application, resico_view_newwin);
	ico_view_next = new FXGIFIcon(&application, resico_view_next);
	ico_view_prev = new FXGIFIcon(&application, resico_view_prev);
	ico_view_refresh = new FXGIFIcon(&application, resico_view_refresh);
	ico_view_split = new FXGIFIcon(&application, resico_view_split);
	ico_view_tilehor = new FXGIFIcon(&application, resico_view_tilehor);
	ico_view_tilever = new FXGIFIcon(&application, resico_view_tilever);
	ico_view_viewdows = new FXGIFIcon(&application, resico_view_viewdows);
	ico_view_workspace = new FXGIFIcon(&application, resico_view_workspace);


	application.init(argc, argv);
	new VisixWindow(&application);
	application.create();

	return application.run();
}
