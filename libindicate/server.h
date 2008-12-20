
#ifndef INDICATE_SERVER_H_INCLUDED__
#define INDICATE_SERVER_H_INCLUDED__ 1

/* Boilerplate */
#define INDICATE_TYPE_SERVER (indicate_server_get_type ())
#define INDICATE_SERVER(object) (G_TYPE_CHECK_INSTANCE_CAST ((object), INDICATE_TYPE_SERVER, IndicateIndicator))
#define INDICATE_IS_SERVER(object) (G_TYPE_CHECK_INSTANCE_TYPE((object), INDICATE_TYPE_SERVER))

typedef struct _IndicateServer IndicateServer;

/* Create a new server */
IndicateServer * indicate_server_new (void);

/* Sets the object.  By default this is /org/freedesktop/indicators */
void indicate_server_set_dbus_object (const gchar * obj);

/* Sets the desktop file to get data like name and description
 * out of */
void indicate_server_set_desktop_file (const gchar * path);

/* Show and hide the server on DBus, this allows for the server to
 * be created, change the object, and then shown.  If for some
 * reason the app wanted to hide all it's indicators, this is a
 * sure fire way to do so.  No idea why, but I'm sure I'll learn. */
void indicate_server_show (IndicateServer * server);
void indicate_server_hide (IndicateServer * server);

/* The functions to count indicators for simpler displays of the
 * indicators in the application */
guint indicate_server_indicator_count (IndicateServer * server);
guint indicate_server_indicator_count_by_type (IndicateServer * server, const gchar * type);


#endif /* INDICATE_INDICATOR_H_INCLUDED__ */
