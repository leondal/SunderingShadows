//      Magic Book for Wizard Characters [v2.0]
//      Thorn@Shadowgate
//      10/10/94 [2.0: 6/8/95]
//      General Wizard Class Items
//      magic_book.c

/* Version History */
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
/*  v2.0  Allows player to have as many spells as s/he wants in the book, */
/* but they must memorize spells in order to cast them. */

#include <std.h>
#include <daemons.h>

#define WIZ_LEV (int)this_player()->query_guild_level("mage")
#define WIZ_CLASS (string)this_player()->query_class()
#define MEMORIZE_DELAY 10

inherit "/std/Object";

mapping spells;
string *magic, *mID;
mixed bookid;
int restore, *spells_at_level;
string owner;
mapping memorized;
int *in_mind;
int lost_book;
nosave int serial_number;

string get_book_id() {
  bookid = get_owner() + get_serial_number();
  set_id( TO->query_id()+ ({ bookid }) );
  save_object("/d/magic/spellbook/"+bookid);
}

void remote_set_spellbook(string spell, int level) {
	object owner;

	if(!level) return;
	if(!spell) return;
	if(!spells_at_level) spells_at_level = ({});
	owner = environment(this_object());
	if(!living(owner)) return;
	spells[spell] = level;
	spells_at_level[level] = spells_at_level[level] + 1;
	save_book();
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
  spells[spell] = level;
  spells_at_level[level] = spells_at_level[level] + 1;
  save_object("/d/magic/spellbook/"+
	      environment(this_object())->query_name());
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
	set_lost_book(0);
}

string query_book_id() {
	return bookid;
}

int query_spellbook(string spell) { return spells[spell]; }

void init() {
	::init();
        if(!(int)TO->query_lost_book()) {
	    add_action("spellbook", "spellbook");
	    add_action("wizlist", "wizlist");
            add_action("spells", "spells");
            add_action("memorize_spell", "memorize");
            add_action("forget_spell", "forget");
        }
	if((owner) && (environment(TO) != find_player(owner))) lose_book();
	add_action("copy", "copy");
        add_action("use_book", "use_book");
        seteuid("MagicBookAccess");
	if(!lost_book) restore_object("/d/magic/spellbook/"+bookid);
	seteuid(getuid());
}

int spellbook() {
  int x, temp;
  magic = keys(spells);
  if(!memorized) memorized = ([]);
  write("--------------------------------------------------------");
  write("Contents of this Spellbook:");
  write("--------------------------------------------------------");
  write(arrange_string("Spell:", 20) + arrange_string("Level:", 10)+
	"* Memorized:"
	);
  write("--------------------------------------------------------\n");
  for(x = 0; x < sizeof(magic);x++) {
    if(member_array(magic[x], keys(memorized)) == -1) temp = 0;
    else temp = query_memorized(magic[x]);
    write(arrange_string(magic[x], 20) +
	  arrange_string(spells[magic[x]], 10) +
	  temp
	  );
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
		notify_fail("Your skill fails you and you botch up the copy."+
                "  You throw away the piece of paper in disgust.\n");
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
          calc = (int)"/daemon/wiz_calcs"->query_spell_limit(x, WIZ_LEV,
							     WIZ_CLASS
                                                             );
          write(arrange_string(x, 25) + calc);
        }
         write("--------------------------------------------------------\n");
        return 1;
}


string get_owner() {
        object pos;

        pos = environment(this_object());
        if(userp(pos)) owner = (string)pos->query_name();
        else if(living(pos)) owner = "monster";
        else owner = "FREE";
        return owner;
}

string query_owner() { return owner; }

void set_owner(string str) { owner = str; }

/* Version 2.0 functions below ------------------v */
int memorize_spell(string str) {
  int temp, sl, allowed_sl;
  object ownr;

  if(!sl = query_spellbook(str)) {
    notify_fail("You do not have that spell in your book to "+
		"memorize! ["+str+"]\n");
    return 0;
  }
  if(!in_mind) in_mind = ({ 0,0,0,0,0,0,0,0,0 });
  if(!memorized) {
    memorized = ([]);
    temp = 0;
  }
  else temp = memorized[str];
  allowed_sl = WIZ_CALCS->query_spell_limit(
					    sl,
					    TP->query_guild_level("mage"),
					    TP->query_class()
					    );
/* Test to see if they can memorize any more spells at the */
/* level of the spell being memorized. -- Thorn 950608 */
  if(in_mind[sl-1] >= allowed_sl) {
    notify_fail("You have memorized all of the spells that you are"+
		" allowed at this level.\n\n");
    return 0;
  }
  write("You begin to memorize the spell.  This may take awhile.");
  call_out("memorize2", sl * MEMORIZE_DELAY, str, sl, temp);
  return 1;
}

void memorize2(string str, int sl, int temp) {
  write("You have now finished memorizing.");
  memorized[str] = temp + 1;
  in_mind[sl-1] += 1;
  write("The spell, \""+str+"\" has been memorized successfully!\n");
  save_object("/d/magic/spellbook/"+bookid);
}

int forget_spell(string str) {
  int temp, sl, allowed_sl;
  object ownr;

  if(!sl = query_spellbook(str)) {
    notify_fail("You do not have that spell in your book to"+
		"forget! ["+str+"]");
    return 0;
  }
  if(!in_mind) in_mind = ({ 0,0,0,0,0,0,0,0,0 });
  if(!memorized) {
    memorized = ([]);
    temp = 0;
  }
  else temp = memorized[str];
  memorized[str] = temp - 1;
  in_mind[sl-1] -= 1;
  write("The spell, \""+str+"\" has been forgotten successfully!\n");
  save_object("/d/magic/spellbook/"+bookid);
  return 1;

}

mapping query_all_memorized() {
  if(!memorized) memorized = ([]);
  return memorized;
}

int query_memorized(string str) {
  if(!memorized) memorized = ([]);
  return memorized[str];
}

// Function that magic_d actually checks.
// Automatically takes away one counter from the number of
// times that the spell has been memorized. -- Thorn 950609
int check_memorized(string str) {
  if(!memorized) memorized = ([]);
  if(member_array(str, keys(memorized)) == -1) return 0;
  else memorized[str] -= 1;
  return memorized[str] + 1;
}

void forget_all_spells() {
  memorized = ([]);
  in_mind = ({ 0,0,0,0,0,0,0,0,0 });
  get_owner();
  save_object("/d/magic/spellbook/"+owner);
 }

void set_memorized(string str, int sl, int xmemorized) {
  int temp, x;

  if(!sl) return;
  if(!xmemorized) x = 1;
  else x = xmemorized;
  if(!memorized) memorized = ([]);
  if(!in_mind) in_mind = ({ 0,0,0,0,0,0,0,0,0 });
  memorized[str] = temp + x;
  in_mind[sl-1] = x;
  get_owner();
  save_book();
}

int save_book() {
        if(!bookid) get_book_id();
	if(!save_object("/d/magic/spellbook/"+bookid)) {
		notify_fail("Error! Failed to save magic book with owner: "+
                            owner+"!\n" );
		return 1;
	}
	else return 1;
}

// Functions that control the behavior of the book while
// it is out of the possession of its owner

void lose_book() {
  string *temp, *new_id, *inv;
  int x;

  if(!new_id) new_id = ({});
  temp = TO->query_id();
  for(x=0;x<sizeof(temp);x++) {
    if(temp[x] != "bookx") new_id += ({ temp[x] });
    else write("Bookx found!");
  }
  remove_action("wizlist", "wizlist");
  remove_action("spells", "spells");
  remove_action("memorize_spell", "memorize");
  remove_action("forget_spell", "forget");
  set_id(new_id);
  for(x=0;x<sizeof(new_id);x++)
    write(new_id[x]);
  lost_book = 1;
}

// Creates a unique serial number for the book so that
// a player may have more than 1 travelling spellbook
// and identify it. -- Thorn 950609
int get_serial_number() {
  serial_number = time();
  return serial_number;
}

int use_book() {
  string old_file;

  if(!(int)TP->query_guild_level("mage")) {
    notify_fail("Only players with magical abilities can use a "+
		"spell book!");
    return 0;
  }
  if(present("bookx", TP)) {
    notify_fail("There is already an active spell book in your "+
	      "possession.  If you want to use the spells from this"+
	      " book you should <copy> them into the book "+
	      "you are using.");
    return 0;
  }
  TO->set_lost_book(0);
  get_book_id();
  set_id(TO->query_id()+({ "bookx" }));
  save_book();
  old_file = "/d/magic/spellbook/"+query_book_id();
  if(!rm(old_file)) {
    log_file("mages", "["+ctime(time())+"] Failure to rm old file in"+
	     " use_book().  [/d/magic/spellbook.c]");
    notify_fail("Spellbook error: Failure in use_book().  Report this"+
		" to an immortal immediately!");
    return 0;
  }
  write("You are now using this spell book!");
  return 1;
}

void enable_spellbook() {
  TO->set_lost_book(0);
  write(find_player("thorn"), "Book enabled correctly!");
  set_id(TO->query_id()+({ "bookx" }));
  TO->move(TP);
  save_book();
}

void set_lost_book(int a) { lost_book = a; }

int query_lost_book() { return lost_book; }
