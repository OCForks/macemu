/*
 *  prefs_amiga.cpp - Preferences handling, AmigaOS specifix stuff
 *
 *  Basilisk II (C) 1997-1999 Christian Bauer
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>

#include "sysdeps.h"
#include "prefs.h"


// Platform-specific preferences items
prefs_desc platform_prefs_items[] = {
	{"sound", TYPE_STRING, false},		// Sound output mode description (audio_amiga.cpp)
	{NULL, TYPE_END, false}	// End of list
};


// Prefs file name
const char PREFS_FILE_NAME[] = "ENV:BasiliskII_prefs";
const char PREFS_FILE_NAME_ARC[] = "ENVARC:BasiliskII_prefs";


/*
 *  Load preferences from settings file
 */

void LoadPrefs(void)
{
	// Read preferences from settings file
	FILE *f = fopen(PREFS_FILE_NAME, "r");
	if (f != NULL) {

		// Prefs file found, load settings
		LoadPrefsFromStream(f);
		fclose(f);

	} else {

		// No prefs file, save defaults
		SavePrefs();
	}
}


/*
 *  Save preferences to settings file
 */

void SavePrefs(void)
{
	FILE *f;
	if ((f = fopen(PREFS_FILE_NAME, "w")) != NULL) {
		SavePrefsToStream(f);
		fclose(f);
	}
	if ((f = fopen(PREFS_FILE_NAME_ARC, "w")) != NULL) {
		SavePrefsToStream(f);
		fclose(f);
	}
}


/*
 *  Add defaults of platform-specific prefs items
 *  You may also override the defaults set in PrefsInit()
 */

void AddPlatformPrefsDefaults(void)
{
}
