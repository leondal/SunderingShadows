//      A Magic Manual
//      Thorn@Shadowgate
//      01/25/01
//      General Wizard Class Items
//      manual.c

#include <std.h>
#include <daemons.h>

inherit OBJECT;

string title;
mapping knowledge;
int usable;

int add_school_knowledge(string school, int level);
int check(string str);
int query_school_knowledge(string school);
int set_manual_properties(mapping book_data);
mapping query_all_knowledge();
string *query_schools();
string query_title();
void set_school_knowledge(mapping all);
void set_title(string str);

int is_magic_manual() { return 1; }

void create() {
    ::create();
    set_name("book");
    set_id(({"manualx", "book", "manual"}));
    set_short("a book");
	set_long("A large, heavy book.  You can <check title>."); 
    set_weight(5);
    set_value(0);
    title = "Untitled "+time();
    usable = random(100);
}

void init() {
	add_action("check", "check");
	add_action("help", "help");
}

void set_title(string str) {
	string lower;
	title = str;
	TO->add_id(str);
	lower = lower_case(str);
	if(lower == str) return;
	TO->add_id(lower_case(str));
}

string query_title() { return title; }

int check(string str) {
	if(!str) return 0;
	if(str != "title") return 0;
    if(interactive(TP) 
        && ((string)TP->is_class("mage")
            || (int)TP->query_guild_level("mage") > 0 
            || (int)TP->query_guild_level("thief") > 0 
            || (int)TP->query_guild_level("bard") > 1 
            || wizardp(TP)) 
        && (usable < (int)TP->query_thief_skill("read languages")  || (TP->is_class("mage") || TP->is_class("bard"))))
        write("This is the manual of magic entitled: "+title+".");
    else
        write("The title is written in some language that you can't read.");
    return 1;
}

string *query_schools() {
	if(!knowledge) {
		knowledge = ([ ]);
	}
	return keys(knowledge);
}

mapping query_all_knowledge() {
	if(!knowledge) {
		knowledge = ([ ]);
		return 0;
	}
	return knowledge;
}

int query_school_knowledge(string school) {
	if(!knowledge) {
		knowledge = ([ ]);
		return 0;
	}
	if(!knowledge[school]) return 0;
	return knowledge[school];
}

void set_school_knowledge(mapping all) {
	if(!knowledge) {
		knowledge = ([ ]);
	}
	knowledge = all;
}

int add_school_knowledge(string school, int level) {
	if(!level) return 0;
	if(!knowledge) {
		knowledge = ([ ]);
	}
	knowledge[school] = level;
	return level;
}

int set_manual_properties(mapping book_data) {

	if(!book_data) return 0;
	
	if(book_data["title"]) TO->set_title(book_data["title"]);
	else return 0;
	if(book_data["long"]) TO->set_long(book_data["long"]);
	if(book_data["short"]) TO->set_short(book_data["short"]);
	if(book_data["knowledge"]) 
		TO->set_school_knowledge(book_data["knowledge"]);
	if(book_data["unique"]) TO->set_unique(1);
	if(book_data["ids"]) TO->set_id(book_data["ids"]);
	return 1;
}