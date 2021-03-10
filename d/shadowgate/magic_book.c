//      Magic Book for Wizard Characters [v1.4.1]
//      Thorn@Shadowgate
//      10/10/94 [1.4.1: 6/3/95]
//      General Wizard Class Items
//      magic_book.c

//	v1.1:	copy function added
//	v1.2:	changed to archiving values on disk in a file
//	v1.2.1	added code to prevent null spells from being added	
//	v1.3	limited the amount and level of spells in the book to
//			coincide with the requirements of Table 21 in the
//			Players Handbook.  Checks WIZ_CALCS daemon.
//  v1.4  Updated the displays for the commands and added the "spells"
//          command to show players haw many spells they get at a level.
//  v1.4.1  Fixed a bug where if the book had no spells, it would fail the
//          check on spell limits and error out.

#include <std.h>
#include <daemons.h>

#define WIZ_LEV (int)this_player()->query_guild_level("mage")
#define WIZ_CLASS (string)this_player()->query_class()

inherit "/std/Object";

mapping spells;
string *magic, *mID;
mixed bookid;
int restore, *spells_at_level;
string owner;

void set_book_id(mixed str) {
	bookid = str;
	this_object()->set_id( ({ "book", "bookx", "magic book",
	"spell book", bookid+".mbook" }) );
	save_object("/d/magic/spellbook/"+bookid);
}

void remote_set_spellbook(string spell, int level) {
	object owner;
	int owner_level, limit, present_spells_at_level;
        string owner_class;
	
	if(!level) return;
	if(!spell) return;
	if(!spells_at_level) spells_at_level = ({});
	owner = environment(this_object());
	if(!living(owner)) return;
        owner_class = owner->query_class();   
	owner_level = owner->query_guild_level("mage");
        limit = WIZ_CALCS->query_spell_limit(level, owner_level, owner_class);
	if(!spells_at_level) present_spells_at_level = 0;
	else present_spells_at_level = spells_at_level[level];
	if(present_spells_at_level < limit) {
		spells[spell] = level;
		spells_at_level[level] = spells_at_level[level] + 1;
		save_object("/d/magic/spellbook/"+bookid);
	}
	if(present_spells_at_level >= limit) {
		tell_player(owner, "You can have no more spells at this level"+
		"in your book!\n");
		return;
	}
}

void set_spellbook(string spell, int level) {
	object owner;
	int owner_level, limit, present_spells_at_level;
        string owner_class;
	
	if(!level) return;
	if(!spell) return;
	if(!spells_at_level) spells_at_level = ({});
	owner = environment(this_object());
	if(!living(owner)) return;
        owner_level = owner->query_guild_level("mage");
        owner_class = owner->query_class();   
        limit = WIZ_CALCS->query_spell_limit(level, owner_level, owner_class);
	if(!spells_at_level) present_spells_at_level = 0;
	else present_spells_at_level = spells_at_level[level];
	if(present_spells_at_level < limit) {
                spells[spell] = level;
                spells_at_level[level] = spells_at_level[level] + 1;
		save_object("/d/magic/spellbook/"+
		environment(this_object())->query_name());
	}
	if(present_spells_at_level >= limit) {
		tell_player(owner, "You can have no more spells at "+
		"this level in your book!\n");
		return;
	}
}

void create() {
        ::create();
        spells = ([]);
	set_id( ({ "book", "bookx", "magic book", 
	"spell book" }) );
        set_weight(10);
        set_value(0);
        set_name("magic book");
        set_short("A Book");
        set_long(
@MAGICK

        This is a wizard's book of magic.  This book is required
        for a wizard to cast any spell whatsoever.  Also, the only
        spells that a wizard may cast are the ones enscribed in
        the book.
        To check which spells are in this particular book type
        <spellbook>.

MAGICK
        );
}

mixed query_book_id() {
	mID = this_object()->query_id();
	bookid = mID[4];
	return bookid; 
}

int query_spellbook(string spell) { return spells[spell]; }

void init() {
	::init();
	add_action("spellbook", "spellbook");
	add_action("copy", "copy");
	add_action("wizlist", "wizlist");
        add_action("spells", "spells");
        seteuid("MagicBookAccess");
	restore_object("/d/magic/spellbook/"+environment(this_object())->query_name());
	seteuid(getuid());
        
}

int spellbook() {
        int x;
        magic = keys(spells);
         write("--------------------------------------------------------");
         write("Contents of this Spellbook:");
         write("--------------------------------------------------------");
         write(arrange_string("Spell:", 25) +"Level:");
         write("--------------------------------------------------------\n");
        for(x = 0; x < sizeof(magic);x++) {
          write(arrange_string(magic[x], 25) + spells[magic[x]]);
        }
         write("--------------------------------------------------------\n");
        return 1;
}

int copy_to_scroll(string str) {
	object paper, pen, ink, scroll;
	string copied_spell;
	int level_multipler, d, multiplier;
	if(!present("paperx", this_player())) {
		notify_fail("You cannot copy without something to "+
                "write on.\n");
		return 0;
	}
	if(!present("penx", this_player())) {
		notify_fail("You cannot copy without something to "+
                "write with.\n");
		return 0;
	}
	if(this_player()->query_guild_level("mage") == 0) {
		notify_fail("Only wizards can read spells, let alone"+
                "copy them.\n");
		return 0;
	}
	level_multipler = this_player()->query_guild_level("mage");
	multiplier = level_multipler * 5;
	if(!str) {
		notify_fail("Copy what spell?");
		return 0;
	}
	copied_spell = str;
	if(spells[str] < 1) {
		notify_fail("The spell '"+str+"' is not in this book!\n");
		return 0;
	}
	paper = present("paperx", this_player());
	pen = present("penx", this_player());
	ink = present("inkx", this_player());
	if(random(100) + multiplier > 99) {
		notify_fail("Your skill fails you and you botch up the copy.  "+
                "You throw away the piece of paper in disgust.\n");
		paper->remove();
		d = ink->query_uses();
		ink->set_uses(d-1);
		return 0;
	}
	scroll = new("/d/magic/mscroll");
	scroll->set_spell_name(str);
	scroll->move(this_player());
	paper->remove();
	d = ink->query_uses();
	ink->set_uses(d-1);
	write("Spell copied sucessfully!\n");
	return 1;
}

int wizlist() {
	if(!wizardp(this_player())) return 0;
	this_player()->more("/d/magic/spellbook/"+bookid);
	return 1;
}

int spells() {
        int x, calc;
         write("--------------------------------------------------------");
         write("Number of Spells Allowed:       [Your level: "+WIZ_LEV+"]");
         write("--------------------------------------------------------");
         write(arrange_string("Spell level:", 25) +"Number allowed:");
         write("--------------------------------------------------------\n");
        for(x = 1; x < 10;x++) {
          calc = (int)"/daemon/wiz_calcs"->query_spell_limit(x, WIZ_LEV, WIZ_CLASS);
          write(arrange_string(x, 25) + calc);
        }
         write("--------------------------------------------------------\n");
        return 1;
}


string get_owner() {
        object pos;
   
        pos = environment(this_object());
        if(interactive(pos)) owner = (string)pos->query_name();
        else if(living(pos)) owner = "monster";
        else owner = "FREE";
        return owner;
}

string query_owner() { return owner; }

void set_owner(string str) { owner = str; }


