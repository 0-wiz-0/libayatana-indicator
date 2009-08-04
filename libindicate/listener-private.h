/*
A library to allow applictions to provide simple indications of
information to be displayed to users of the application through the
interface shell.

Copyright 2009 Canonical Ltd.

Authors:
    Ted Gould <ted@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of either or both of the following licenses:

1) the GNU Lesser General Public License version 3, as published by the 
Free Software Foundation; and/or
2) the GNU Lesser General Public License version 2.1, as published by 
the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR 
PURPOSE.  See the applicable version of the GNU Lesser General Public 
License for more details.

You should have received a copy of both the GNU Lesser General Public 
License version 3 and version 2.1 along with this program.  If not, see 
<http://www.gnu.org/licenses/>
*/

#ifndef INDICATE_LISTENER_PRIVATE_H__ 
#define INDICATE_LISTENER_PRIVATE_H__ 1

struct _IndicateListenerServer {
	gchar * name;
	DBusGProxy * proxy;
	DBusGConnection * connection;
	gboolean interests[INDICATE_INTEREST_LAST];
};

struct _IndicateListenerIndicator {
	guint id;
};

typedef struct _IndicateListenerPrivate IndicateListenerPrivate;
struct _IndicateListenerPrivate
{
	DBusGConnection * session_bus;
	DBusGConnection * system_bus;

	DBusGProxy * dbus_proxy_session;
	DBusGProxy * dbus_proxy_system;

	GList * proxies_working;
	GList * proxies_possible;

	GArray * proxy_todo;
	guint todo_idle;
};

#define INDICATE_LISTENER_GET_PRIVATE(o) \
		(G_TYPE_INSTANCE_GET_PRIVATE ((o), INDICATE_TYPE_LISTENER, IndicateListenerPrivate))

#endif /* INDICATE_LISTENER_PRIVATE_H__ */
