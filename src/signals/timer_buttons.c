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

#include "timer_buttons.h"
#include "../structures.h"
#include "../features/timer.h"
#include <stdbool.h>
#include <gtk/gtk.h>

void
start_signal(GtkWidget *widget,
             struct TimerUI *timerUi)
{
    if (timerUi->timerReference != 0)
        return;

    timerUi->timerReference = g_timeout_add(1000, G_SOURCE_FUNC(run_timer), timerUi);
}

void
pause_signal(GtkWidget *widget,
             struct TimerUI *timerUi)
{
    if (timerUi->timerReference != 0)
        g_source_remove(timerUi->timerReference);

    timerUi->timerReference = 0;
}

void
reset_signal(GtkWidget *widget,
             struct TimerUI *timerUi)
{
    pause_timer(timerUi);
    reset_timer(timerUi);
}
