// qpwgraph_form.h
//
/****************************************************************************
   Copyright (C) 2021-2022, rncbc aka Rui Nuno Capela. All rights reserved.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*****************************************************************************/

#ifndef __qpwgraph_form_h
#define __qpwgraph_form_h

#include "ui_qpwgraph_form.h"


// Forward decls.
class qpwgraph_config;

class qpwgraph_sect;
class qpwgraph_pipewire;
class qpwgraph_alsamidi;

class qpwgraph_item;
class qpwgraph_port;

class qpwgraph_systray;

class QResizeEvent;
class QCloseEvent;

class QSlider;
class QSpinBox;

class QActionGroup;


//----------------------------------------------------------------------------
// qpwgraph_form -- UI wrapper form.

class qpwgraph_form : public QMainWindow
{
	Q_OBJECT

public:

	// Constructor.
	qpwgraph_form(QWidget *parent = nullptr,
		Qt::WindowFlags wflags = Qt::WindowFlags());

	// Destructor.
	~qpwgraph_form();

protected slots:

	// Node life-cycle slots
	void added(qpwgraph_node *node);
	void removed(qpwgraph_node *node);

	// Port (dis)connection slots.
	void connected(qpwgraph_port *port1, qpwgraph_port *port2);
	void disconnected(qpwgraph_port *port1, qpwgraph_port *port2);

	// Item renaming slot.
	void renamed(qpwgraph_item *item, const QString& name);

	// Graph section slots.
	void pipewire_changed();
	void alsamidi_changed();

	// Pseudo-asynchronous timed refreshner.
	void refresh();

	// Graph selection change slot.
	void stabilize();

	// Tool-bar orientation change slot.
	void orientationChanged(Qt::Orientation orientation);

	// Main menu slots.
	void viewMenubar(bool on);
	void viewToolbar(bool on);
	void viewStatusbar(bool on);

	void viewTextBesideIcons(bool on);

	void viewCenter();
	void viewRefresh();

	void viewZoomRange(bool on);

	void viewSortTypeAction();
	void viewSortOrderAction();

	void viewColorsAction();
	void viewColorsReset();

	void helpAbout();
	void helpAboutQt();

	void zoomValueChanged(int zoom_value);

	void closeQuit();

protected:

	// Context-menu event handler.
	void contextMenuEvent(QContextMenuEvent *event);

	// Widget resize event handler.
	void resizeEvent(QResizeEvent *event);

	// Widget event handlers.
	void showEvent(QShowEvent *event);
	void hideEvent(QHideEvent *event);
	void closeEvent(QCloseEvent *event);

	// Special port-type color method.
	void updateViewColorsAction(QAction *action);
	void updateViewColors();

	// Item sect predicate.
	qpwgraph_sect *item_sect(qpwgraph_item *item) const;

	// Restore/save whole form state...
	void restoreState();
	void saveState();

private:

	// The Qt-designer UI struct...
	Ui::qpwgraph_form m_ui;

	// Instance variables.
	qpwgraph_config *m_config;

	qpwgraph_pipewire *m_pipewire;
	qpwgraph_alsamidi *m_alsamidi;

	int m_pipewire_changed;
	int m_alsamidi_changed;

	int m_ins, m_mids, m_outs;

	QSlider  *m_zoom_slider;
	QSpinBox *m_zoom_spinbox;

	QActionGroup *m_sort_type;
	QActionGroup *m_sort_order;

	qpwgraph_systray *m_systray;
};


#endif	// __qpwgraph_form_h

// end of qpwgraph_form.h
