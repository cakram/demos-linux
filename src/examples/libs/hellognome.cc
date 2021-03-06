/*
 * This file is part of the linuxapi package.
 * Copyright (C) 2011-2018 Mark Veltzer <mark.veltzer@gmail.com>
 *
 * linuxapi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * linuxapi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with linuxapi. If not, see <http://www.gnu.org/licenses/>.
 */

#include <firstinclude.h>
#include <gnome.h>	// for gnome_init(3), gnome_app_new(3), gtk_widget_show(3), gtk_main(3)

/*
 * This is a demo program for using C Gnome
 *
 * EXTRA_LINK_CMDS=pkg-config --libs libgnomeui-2.0
 * EXTRA_COMPILE_CMDS=pkg-config --cflags libgnomeui-2.0
 */

int main(int argc, char** argv, char** envp) {
	gnome_init("mdi-test", "1.0", argc, argv);
	GtkWidget* w=gnome_app_new("mdi-test", "1.0");
	gtk_widget_show(w);
	gtk_main();
	return EXIT_SUCCESS;
}
