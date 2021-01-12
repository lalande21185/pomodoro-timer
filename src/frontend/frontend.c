/*
Copyright (C) 2021 Github profile https://github.com/lalande21185

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "frontend.h"
#include "../structures.h"
#include <stdbool.h>
#include <gtk/gtk.h>

bool
init_view(GtkBuilder *builder)
{
    GError *error = NULL;

    //if (gtk_builder_add_from_file(builder, "/usr/local/share/main/view.glade", &error) == 0) {
    if (gtk_builder_add_from_file(builder, "src/frontend/view.glade", &error) == 0) {
        g_warning("%s", error->message);
        g_clear_error(&error);
        return false;
    }

    return true;
}

bool
init_style(struct TimerUI *timerUi)
{
    GtkStyleContext *context;
    GtkCssProvider *provider;
    GError *error = NULL;

    context = gtk_widget_get_style_context(GTK_WIDGET(timerUi->label));
    provider = gtk_css_provider_new();

    //gtk_css_provider_load_from_path(provider, "/usr/local/share/main/style.css", &error);
    gtk_css_provider_load_from_path(provider, "src/frontend/style.css", &error);
    if (error) {
        g_warning("%s", error->message);
        g_clear_error(&error);
        return false;
    }

    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    return true;
}
