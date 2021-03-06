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

#ifndef TIMER_BUTTONS_H_INCLUDED
#define TIMER_BUTTONS_H_INCLUDED

void    start_signal    (GtkWidget*,
                         struct TimerUI*);

void    pause_signal   (GtkWidget*,
                        struct TimerUI*);

void    reset_signal    (GtkWidget*,
                         struct TimerUI*);

#endif // TIMER_BUTTONS_H_INCLUDED
