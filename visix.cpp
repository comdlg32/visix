#include <fx.h>
#include "res/foxres.h"

FXIcon* mainIcon;

class VisixWindow : public FXMainWindow {
	FXDECLARE(VisixWindow)

private:
	FXDockSite*     topdock;
	
	FXToolBarShell* tsmenubar;
	FXMenuBar*      menubar;

	FXButton* btn;

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

VisixWindow::VisixWindow(FXApp *a) : FXMainWindow(a, "Visix", mainIcon, NULL, DECOR_ALL, 0,0,0,0) {
	topdock = new FXDockSite(this, LAYOUT_SIDE_TOP|LAYOUT_FILL_X);
	
	tsmenubar = new FXToolBarShell(this);
	menubar = new FXMenuBar(topdock, tsmenubar, LAYOUT_FILL_X|FRAME_RAISED);

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

	new FXStatusBar(this, LAYOUT_FILL_X|LAYOUT_SIDE_BOTTOM|STATUSBAR_WITH_DRAGCORNER);

	btn = new FXButton(this, "o/", NULL, this, ID_EXAMPLE);
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

	mainIcon = new FXGIFIcon(&application, resico_mainicon);

	application.init(argc, argv);
	new VisixWindow(&application);
	application.create();

	return application.run();
}
