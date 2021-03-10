// Permanent Spells information command
// Permanent Spell System
// Thorn@ShadowGate
// 21 March 2001
// _permspells.c


#include <writef.h>
#include <daemons.h>
#include <std.h>

#define DIV       "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
#define DIVIDER   DIV+DIV
#define PSPELL_D  "/daemon/permspell"

inherit DAEMON;

int cmd_permspells(string arg) {
	mapping pspells, row, cref;
	string *skeys;
	string cname, tpath, sname, spath;
	object spell;
	int clevel;

	string line, str2, zone_name;
	string *argv;
	int i, do_more, time_zone, xyzpdq;

	pspells = PSPELL_D->dump();
	skeys = keys(pspells);
	cref = ([ ]);


	line = DIVIDER + "\n";
	line += "Spell                    | Caster     | Lev. | Location\n";
	line += DIVIDER + "\n";

	if(sizeof(skeys) < 1) {
		line += "No permanent spells active.\n";
		line += DIVIDER + "\n";
		message("Nsystem", line, this_player());
		return 1;
	}

	for (i=0; i<sizeof(skeys); i++) {
		row = pspells[skeys[i]];
		cname = row["castername"];
		clevel = row["casterlevel"];
		tpath = row["targetpath"];
		spath = row["spellpath"];

		// Use a cross-reference mapping to avoid cloning spells to get
		// the names for which the name has already been discovered
		// once.
		if(!cref[spath]) {
			spell = new(spath);
			sname = spell->query_spell_name();
			cref[spath] = sname;
		}
		else {
			sname = cref[spath];
		}
		
		cname = capitalize(cname);
		line += sprintf("%-24s", sname);
		line += " | ";
		line += sprintf("%-10s", cname);
		line += " | ";
		line += sprintf("%-4d", clevel);
		line += " | ";
		line += sprintf("%-32s", tpath);
		line += "\n";
	}
	line += DIVIDER + "\n";
	message("Nsystem", line, this_player());
	return 1;  
}
