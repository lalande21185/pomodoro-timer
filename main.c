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

#include <stdlib.h>
#include <gtk/gtk.h>
#include <time.h>
#include <glib.h>
#include <stdbool.h>
#include "src/structures.h"
#include "src/signals/options.c"
#include "src/signals/timer_buttons.c"
#include "src/frontend/frontend.c"
#include "src/features/timer.c"

int
main (int argc,
      char **argv)
{
    GtkBuilder *builder;
    GtkWidget *window;
    struct TimerUI timerUi;
    bool success;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    // set up user interface
    success = init_view(builder);
    if (!success)
        return 1;

    // get and set up window
    window = GTK_WIDGET( gtk_builder_get_object (builder, "window"));
    timerUi.window = GTK_WINDOW(window);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_title(GTK_WINDOW(window), "Pomodoro Timer");

    // connect signals to builder
    gtk_builder_connect_signals(builder, &timerUi);

    // timer
    init_timer(builder, &timerUi);

    // style
    success = init_style(&timerUi);
    if (!success)
        return 1;

    // start
    gtk_widget_show(window);
    gtk_main();

    return 0;
}

