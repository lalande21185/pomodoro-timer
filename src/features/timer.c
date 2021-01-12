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

#include "timer.h"
#include "../structures.h"
#include <stdbool.h>
#include <gtk/gtk.h>

void
init_timer(GtkBuilder *builder,
           struct TimerUI *timerUi)
{
    // ui
    timerUi->label = GTK_LABEL(gtk_builder_get_object(builder, "timer"));

    // timer callback reference
    timerUi->timerReference = 0;

    // reset
    reset_timer(timerUi);
}

void
reset_timer(struct TimerUI *timerUi)
{
    timerUi->minutes = 25;
    timerUi->seconds = 0;
    gtk_label_set_text(timerUi->label, "25:00");
}

void
pause_timer(struct TimerUI *timerUi)
{
    if (timerUi->timerReference != 0)
        g_source_remove(timerUi->timerReference);

    timerUi->timerReference = 0;
}

gboolean
run_timer(struct TimerUI *timerUi)
{
    if (timerUi->seconds == 0 && timerUi->minutes == 0) {
        pause_timer(timerUi);
        return true;
    }

    char formattedTime[6];
    char formattedSeconds[3];

    if (timerUi->seconds == 0)
        timerUi->seconds = 59;
    else
        timerUi->seconds = timerUi->seconds - 1;

    if (timerUi->seconds == 59)
        timerUi->minutes = timerUi->minutes - 1;

    if (timerUi->seconds < 10 && timerUi->seconds >= 0)
        snprintf(formattedSeconds, 3, "0%d", timerUi->seconds);
    else
        snprintf(formattedSeconds, 3, "%d", timerUi->seconds);

    snprintf(formattedTime, 6, "%d:%s", timerUi->minutes, formattedSeconds);

    gtk_label_set_text(GTK_LABEL(timerUi->label), formattedTime);

    return true;
}
