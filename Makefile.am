bin_PROGRAMS = main
main_SOURCES = main.c
main_CPPFLAGS = $(GTK_CFLAGS)
main_LDADD = $(GTK_LIBS)
main_LDFLAGS = -rdynamic

desktopdir = $(datadir)/applications
desktop_in_files = main.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)

appicondir = $(datadir)/icons
appicon_DATA = icon.png

gladedir = $(pkgdatadir)
glade_DATA = src/frontend/view.glade

cssdir = $(pkgdatadir)
css_DATA = src/frontend/style.css
