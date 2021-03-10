//      Test Magic Book for Immortals [Magic Book v1.3]
//      Thorn@Shadowgate
//      2/14/95
//      General Wizard Class Items
//      test_book.c

// DO NOT allow this book to fall into the hands of mortal
// players! -- Thorn

#include <std.h>
#include <daemons.h>

void wizadd(string str, int a);

inherit "/std/Object";

mapping spells;
string *magic, *mID;
mixed bookid;
int restore, *spells_at_level;

void set_book_id(mixed str) {
        bookid = str;
        this_object()->set_id( ({ "book", "bookx", "magic book", "spell book", bookid+".mbook" }) );
        save_object("/d/magic/spellbook/"+bookid);
}

void remote_set_spellbook(string spell, int level) {
        if(!level) return;
        if(!spell) return;

        spells[spell] = level;
        save_object("/d/magic/spellbook/"+bookid);
}

void set_spellbook(string spell, int level) {
        int owner_level, limit;

        if(!level) return;
        if(!spell) return;

                if(!spells[spell]){ // not there?
                        spells[spell] = level;
                } else {
                        // kinda self explainetory
                        write("You already have that spell in your book!.");
                        return;
                }

                save_object("/d/magic/spellbook/"+TP->query_name());
        return;
}

void create() {
        ::create();
        spells = ([]);
        spells_at_level = allocate(21);
        set_id( ({ "book", "bookx", "test book", "testx" }) );
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
		THIS IS A TEST VERSION OF THE SPELLBOOK.  FOR AUTHORIZED
		USE ONLY!
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
	add_action("wizadd", "wizadd");
        add_action("wizlist", "wizlist");
        restore_object("/d/magic/spellbook/"+environment(this_object())->query_name());
}

int spellbook() {
        int x;
        magic = keys(spells);
                write("%^RED%^BOLD%^Contents of this Spell Book%^RESET%^");
                write("%^RED%^BOLD%^=-=-=-=-=-=-=-=-=-=-=-=-=-=\n%^RESET%^");
        for(x = 0; x < sizeof(magic);x++) {
          write(magic[x]);
        }
                write("\n");
        return 1;
}

int copy(string str) {
        object paper, pen, ink, scroll;
        string copied_spell;
        int level_multipler, d, multiplier;
        if(!present("paperx", this_player())) {
                notify_fail("You cannot copy without something to write on.\n");
                return 0;
        }
        if(!present("penx", this_player())) {
                notify_fail("You cannot copy without something to write with.\n");
                return 0;
        }
        if(this_player()->query_guild_level("mage") == 0) {
                notify_fail("Only wizards can read spells, let alone copy them.\n");
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
                notify_fail("Your skill fails you and you botch up the copy. You throw away the piece of paper in disgust.\n");
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

void wizadd(string str, int a) {
	if(!str) return;
	if(!a) a = 1;
	this_object()->set_spellbook(str, a);
        write("Spell: "+str+" Level: "+a+" added successfully.\n");
}

