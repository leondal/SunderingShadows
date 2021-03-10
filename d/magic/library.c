// mage library

#include <std.h>
#include <move.h>
#include <flags.h>
#include <spell_research.h>

#define SAVE_FILE "/d/magic/library/"
#define PROMPT "RSRCH -> "

// Maximum proficency in a spell that can be attained by
// research into the spell

inherit VAULT;

int allowed_storage = 10;
int locked;
string lib_id;
mapping books = ([ ]);
mapping collection = ([ ]);
int quantity;

mapping rqueue = ([ ]);
mapping notes;
nosave mapping rcache = ([ ]);

int help(string str);
int help(string str);
int list(string str);
int obtain(string str);
int query_allowed_storage();
int query_book(string title);
int query_book_quantity();
int query_collection(string school);
int remove_book(string title);
int shelve(string str);
int wizadd(string str);
int wizremove(string str);
mapping query_book_data(string title);
string *query_books();
string getLibId();
void add_book(object book);
void add_collection(string school, string level);
void listBooks();
void remove_collection(string school, string level);
void setAllowedStorage(int xxx);
void set_locked(int x);

int start_shell();
int rshell(string str);
int stop_shell();
int copy_notes();
int list_comp(string str);
int add_comp(string str);
int show_notes(string str);
int clear_notes(string str);
int remove_comp(string str);
int study(string str);
int shell_help(string str);
int max_rsrch_pts(int level);
void dequeue(string qref);
string enqueue(mapping job);
int stop_study(string str, string qref);
int research_director(mapping job);
int keywords();
int search(string str);
int rstop(string qref);
int transcribe(string spell);
int master_book();

void Save(){
   save_object(SAVE_FILE+lib_id);
}

void Restore(){
   restore_object(SAVE_FILE+lib_id);
}


void create() {
   ::create();
   notes = ([ ]);
   TO->Restore();

}

void setAllowedStorage(int xxx) {
   allowed_storage= xxx;
}


int query_allowed_storage() {
   return allowed_storage;
}

void setLibId(string id) {
   lib_id = id;
   TO->Restore();
}

string getLibId() {
   return lib_id;
}

void init() {
   ::init();

   add_action("shelve","shelve");
   add_action("obtain","obtain");
   add_action("wizadd","wizadd");
   add_action("wizremove","wizremove");
   add_action("list","list");
   add_action("request","request");
   add_action("collection","collection");
   add_action("help","help");
   add_action("research","research");
}

int shelve(string str) {
   int amount;
   string stuff;
   object ob;
   object book;

	if(locked) {
		write("You cannot do that in this library.");
		return 1;
	}

    if(!str) {
        return help("library");
    }

    if(!book = present(str, TP)) {
        tell_object(TP,"%^BOLD%^RED%^You do not have that item!");
        return 1;
    }

    if(!book->is_magic_manual()) {
        tell_object(TP,"%^BOLD%^RED%^That item does not belong on your bookshelf!");
        return 1;
    }

    if(!file_exists(SAVE_FILE+lib_id+".o")) {

    }

   TO->Save();

   if((int)TO->query_book_quantity() + 1 > allowed_storage) {
      tell_object(TP,"No more space in this bookshelf.");
      return 1;
   }

   TO->add_book(book);
   TO->Save();

   tell_object(TP,"%^BOLD%^You carefully take your "+book->query_title()+" and place it on your bookshelf.");
   tell_room(TO,"%^BOLD%^"+TPQCN+" carefully takes some "+book->query_title()+" and places it on "+TP->query_possessive()+" bookshelf.",TP);
   book->remove();
   return 1;

}

int obtain(string str) {
	object book;
	int amount;
	string stuff;
	mapping btemp;


	if(locked) {
		write("You cannot take the books from this library");
		return 1;
	}

	if(!str) {
	  return help("library");
	}

	if(sscanf(str, "%d %s",amount, stuff) != 2) {
	  stuff = str;
	  amount = -1;
	}

	if(!file_exists(SAVE_FILE+lib_id+".o")) {
	}

	TO->Restore();
	TO->Save();

	if (!TO->query_book(str)) {
	    return notify_fail("You have no book entitled "+str+" on your bookshelf.\n");
	}

	book = new("/d/magic/manual");
	btemp = TO->query_book_data(str);
	book->set_manual_properties(btemp);
	TO->remove_book(str);
	TO->Save();

	if( (int)(book->move(TP)) != MOVE_OK ) {
	    write("You drop the book to the floor as soon as you select it!");
	    book->move(ETP);
	}
	else book->move(TP);

	tell_object(TP,"%^BOLD%^You obtain the manual titled "+str+" from your bookshelf here.");
	tell_room(TO,"%^BOLD%^"+TPQCN+" obtains a book from a bookshelf.",TP);
	return 1;
	}

	int list(string str){
	string *titles;
	int i,j;

	if (!str) {
	  return notify_fail("List what?\n");
	}

	if (str != "books") {
	  return notify_fail("List what?\n");
	}

	titles = keys(books);

	j = sizeof(books);
	write("%^ORANGE%^<==========================>");
	write(" %^ORANGE%^    Books on this shelf    ");
	write("%^ORANGE%^<==========================>");
	for (i=0;i<j;i++) {
	  write("%^ORANGE%^ "+titles[i]);
	}
	return 1;
}


int help(string str){

   if (!str) {
      return 0;
   }

   if (str != "library") {
      return 0;
   }

   write("<============================>");
   write("       Library Help");
   write("<============================>\n");
   write(" shelve <book name> shelves a book you possess");
   write(" obtain <book name>: obtains a book from your bookshelf");
   write(" list books: lists the contents of this library");
   write(" help library: shows this screen.");
   if(avatarp(TP)) {
		write("\n<============================>");
		write("       Avatar Commands");
		write("<============================>\n");
		write(" collection: Shows the schools and knowledge levels in this library.");
		write(" wizadd <title>, <school>, <level>: Add a book to this library\n"
              "   without having the book.");
		write(" wizremove <title>: Remove a book from this library w/o having\n"
              "   to get a book back.");
   }
   return 1;
}

void add_book(object book) {
	mapping book_data;
	mapping temp;
	string title, *schools;
	int i;

	if(!objectp(book)) return;

	book_data = ([ ]);
	book_data["long"] = book->query_long();
	book_data["short"] = book->query_short();
	temp = book_data["knowledge"] = book->query_all_knowledge();
	schools = book->query_schools();
	book_data["unique"] = book->query_unique();
	book_data["ids"] = book->query_id();
	title = book_data["title"] = book->query_title();

	if (!books) {
		books = ([]);
	}
	books[title] = book_data;

	for(i=0;i<sizeof(schools);i++) {
		add_collection(schools[i], temp[schools[i]]);
	}
	quantity++;
	TO->save();
	return;
}

int remove_book(string title) {
	mapping book_data, temp;
	string *schools;
	int level, i;

	if(!books) {
		books = ([ ]);
		return 0;
	}
	if(!books[title]) return 0;

	book_data = books[title];
	temp = book_data["knowledge"];
	schools = keys(temp);
	for(i=0;i<sizeof(schools);i++) {
		remove_collection(schools[i], temp[schools[i]]);
	}
	map_delete(books, title);
	quantity--;
	TO->save();
	return 1;
}

int query_book(string title) {
	if(!books) {
		books = ([ ]);
		return 0;
	}
	if(!books[title]) return 0;
	return 1;
}

string *query_books() {
	string *retval;

	if(!books) {
		books = ([ ]);
		return 0;
	}
	retval = keys(books);
	return retval;
}

mapping query_book_data(string title){
	mapping book_data;

	if(!books) {
		books = ([ ]);
		return 0;
	}
	if(!books[title]) return 0;

	book_data = books[title];
	return book_data;
}

void listBooks(){
   string *titles;
   int i,j;

   titles = keys(books);

   j = sizeof(books);
   write("%^ORANGE%^<==========================>");
   write(" %^ORANGE%^    Books on this shelf    ");
   write("%^ORANGE%^<==========================>");
   for (i=0;i<j;i++) {
      write("%^ORANGE%^ "+titles[i]);
   }
}

int query_collection(string school) {
	if(!collection) {
		collection = ([ ]);
		return 0;
	}
	if(!collection[school]) return 0;
	return collection[school];
}

void add_collection(string school, string level) {
	if(!collection) {
		collection = ([ ]);
	}
	collection[school] += level;
}

void remove_collection(string school, string level) {
	if(!collection) {
		collection = ([ ]);
		return;
	}
	collection[school] -= level;
	if(collection[school] < 1) {
		map_delete(collection, school);
	}
	return;
}

int query_book_quantity() {
	return quantity;
}

string *query_schools() {
	return keys(collection);
}

//////////////////////////////////////
int wizadd(string str) {
   int amount, level;
   string title, school;
   object book;

	if(!avatarp(TP)) return 0;
    if(!str) {
        return write("Usage: wizadd <title>, <school>, <book level>");
    }

    if(sscanf(str, "%s, %s, %d", title, school, level) != 3) {
        return write("Usage: wizadd <title>, <school>, <book level>");
	}

	if((int)TO->query_book_quantity() + 1 > allowed_storage) {
		write("You are overflowing this library.  Hope that's okay.");
	}

	book = new("/d/magic/manual");
	book->add_school_knowledge(school, level);
	book->set_title(title);
	TO->add_book(book);
	TO->Save();

   write("You add the book called, "+str+", to this library.");
   return 1;

}


int wizremove(string str) {
   object book;
   int amount;
   string stuff;
   mapping btemp;

	if(!avatarp(TP)) return 0;
    if(!str) {
        return write("Usage: wizremove <title>");
    }

    if (!TO->query_book(str)) {
        return notify_fail("There is no book entitled, "+str+", on this bookshelf.\n");
    }

    TO->remove_book(str);
    TO->Save();

    if( (int)(book->move(TP)) != MOVE_OK ) {
        write("You drop the book to the floor as soon as you select it!");
        book->move(ETP);
    }
    else book->move(TP);

	write("You get the book called, "+str+", from this library.");
    return 1;
}

int collection() {
	string *schools;
	string sch;
	int lev, i, j;

	if(!avatarp(TP)) return 0;

	schools = TO->query_schools();
	j = sizeof(schools);

	write("%^BLUE%^BOLD%^<==================================>");
	write("%^CYAN%^BOLD%^  Knowledge Levels in this Library    ");
	write("%^BLUE%^BOLD%^<==================================>");
	for (i=0;i<j;i++) {
		sch = schools[i];
		lev = TO->query_collection(sch);
		write("%^BOLD%^ "+arrange_string(sch,30)+" %^GREEN%^"+arrange_string(lev,5));
	}
	return 1;
}

int research(string str) {
	if(!TP->query_guild_level("mage")) {
		write("The books in this library mean nothing to you!");
		return 1;
	}
	write("You are now researching.  You can type 'end' on a line to "
	      "stop researching.  You can type 'help' for a list of commands "
	      "and 'help <command name>' for information on a command.\n");
	message("prompt", PROMPT, TP);
	input_to("rshell", I_NOESC);
	return 1;
}

int rshell(string str) {
	string cmd, arg;
	int tokens;
	if(!str || str == "\n") {
		message("prompt", PROMPT, TP);
		input_to("rshell", I_NOESC);
		return 1;
	}
	if(str == "quit") return stop_shell();
	if(str == "end") return stop_shell();

	tokens = sscanf(str, "%s %s", cmd, arg);
	if(!tokens) cmd = str;
	if(cmd == "quit") return stop_shell();
	else if(cmd == "copy") return copy_notes();
	else if(cmd == "components") return list_comp(arg);
	else if(cmd == "add") return add_comp(arg);
	else if(cmd == "notes") return show_notes(arg);
	else if(cmd == "clear") return clear_notes(arg);
	else if(cmd == "remove") return remove_comp(arg);
	else if(cmd == "study") return study(arg);
	else if(cmd == "search") return search(arg);
	else if(cmd == "keywords") return keywords();
	else if(cmd == "transcribe") return transcribe(arg);
	else if(cmd == "master") return master_book();
	else if(cmd == "help") return shell_help(arg);
	else {
		write("Invalid command.");
		message("prompt", PROMPT, TP);
		input_to("rshell", I_NOESC);
	}
    return 1;
}

int stop_shell() {
	write("You stop researching.\n");
	return 1;
}

int copy_notes() {
	write("You finalize your thoughts and copy your notes to paper.\n");
	return 1;
}

int shell_help(string str) {
	write("%^BOLD%^CYAN%^Spell Research Help system%^RESET%^\n");
	if(str == "quit" || str == "end") {
		write("Usage: quit|end\n\nEnds your research WITHOUT copying "+
		      "your notes to a notebook for constructing a new spell.\n\n"+
		      "See: copy");
	}
	else if(str == "copy") {
		write("Usage: copy notes\n\nCopys your notes to a notebook for "+
		      "bringing to another location.  Also, you will need to "+
		      "copy your notes to a notebook to create any new spell in "+
		      "from your research.\n\nSee: end, quit");
	}
	else if(str == "components") {
		write("Usage: components\n\nAllows you to inspect your components "+
	          "bag while in the shell.");
	}
	else if(str == "add") {
		write("Usage: add <component name>\n\nAdds a new component to your "+
	          "your notes in sequence.");
	}
	else if(str == "notes") {
		write("Usage: notes\n\nAllows you to view the research that you "+
	          "are working with at the moment.  The notes here can be "+
	          "transferred to a parchment when you are ready to finalize "+
	          "your research on this particular spell or if you simply "+
	          "want to work in another location.\n\nSee: copy");
	}
	else if(str == "clear") {
		write("Usage: clear notes\n\nStart over again with a completely new "+
	          "combination of components.");
	}
	else if(str == "remove") {
		write("Usage: remove <component name>\n\nRemoves a component from your "+
	          "your notes off the end of the sequence.");
	}
	else if(str == "study") {
		write("Usage: study school|spell <name>\n\nConsult your library either "+
	          "to research new spells or to increase your "+
	          "proficency in a particular spell.\n\nYou may not study a spell "+
	          "to gain a proficency higher than "+MAX_PROF+" percent.  Any "+
	          "further proficency must be gained through use of the spell.\n\n"+
	          "See: schools");
	}
	else if(str == "schools") {
		write("The recognized schools of magic in the realms are:\n"
	          "invocation_evocation\n"
	          "conjuration_summoning\n"
	          "alteration\n"
	          "necromancy\n"
	          "divination\n"
	          "abjuration\n\n"
		);
	}
	else if(str == "transcribe") {
		write("Usage: transcribe <spell name>\n\nAllows you to transcribe "+
	          "a spell from your master spell book to a travelling spell "+
	          "book in your possession.");
	}
	else if(str == "master") {
		write("Usage: master\n\nAllows you to view the spells that you "+
	          "have in your master spell book.  Your master spell book "+
	          "is always available at a library for viewing.");
	}
	else if(str == "search") {
		write("Usage: search school randomly|for <keyword, keyword, ....\n\n "+
	          "A random search will put you on track for the first spell that "+
	          "you might come across in a school of magic.  A keyword search "+
	          "will allow you to narrow down your search to a spell you might "+
	          "have more of an interest in.  Keep in mind, however, not all "+
	          "spells have keywords, and so some spells must be searched for "+
	          "randomly.\n\n"+
	          "See: keywords");
	}
	else if(str == "keywords") {
		write("You may do a keyword spell search with the following words:\n"+
			implode(SRD->get_keywords(), "\n"));
	}
	else {
//		write("Available commands in this shell "+
//		      "are: quit, copy, components, add, notes, clear, "+
//		      "remove, study and help.\n\n");
		write("Available commands in this shell "+
		      "are: quit, end, study, transcribe, master, and help.\n\n");
		write("You can type 'help <command>' to get help for that "+
		      "specific command.\n");
	}
	message("prompt", PROMPT, TP);
	input_to("rshell", I_NOESC);
    return 1;
}

int research_event() {
	int i, jobs, level;
	object current;
	mapping job;
	string type, school, qref;
	int intel, know, pts, intbonus, current_points;
	float bonus;
	string *qrefs;
	string *keywords;

	qrefs = keys(rqueue);
	jobs = sizeof(qrefs);
	if(!jobs) {
//		tell_object(find_player("thorn"), "No jobs found in rqueue.");
		return 1;
	}
//	tell_object(find_player("thorn"), "Job(s) found in rqueue.");
	for(i=0;i<jobs;i++) {
		qref = qrefs[i];
		job = rqueue[qref];
		current = job["user"];
		type = job["type"];
		school = job["school"];
		keywords = job["keywords"];
		current_points = job["points"];

		know = query_collection(school);
		intel = current->query_stats("intelligence");
		level = current->query_guild_level("mage");
		if(school == (string)current->query_school())
			bonus = SPEC_RSRCH_BONUS;
		else bonus = 1;

		/* THE Spell Research formula */
		intbonus = (intel - BASE_INT) * INT_BONUS_MULTIPLIER;
		pts = random(to_int(know * bonus)) + intbonus;
		/*                            */

		current_points += pts;

		if(current_points > max_rsrch_pts(level)) {
			tell_object(current, "You feel that you do not "+
				"have enough experience to comprehend anything else.");
			current_points = max_rsrch_pts(level);
		}
		job["points"] = current_points;
		rqueue[qref] = job;
//	    tell_object(find_player("thorn"), "current = "+file_name(current));
		if(avatarp(current))
			tell_object(current, "PTS: "+current_points+" (+"+pts+") ("+know+" * "+bonus+") + "+intbonus+"");
		tell_object(current, "You are happily researching away....");
		if(!research_director(job)) {
			dequeue(qref);
			rstop(qref);
		}
	}

	call_out("research_event", 2);
//	tell_object(find_player("thorn"), "Callout made in research_event().");
	return 1;
}

int transcribe(string spell) {
	object book;
	int prof, level, cost;

	level = SRD->get_spell_level(spell);
	if(!level) {
		// That's not a spell.
		message("prompt", PROMPT, TP);
		input_to("rshell", I_NOESC);
		return 1;
	}
	level--;
	cost = TRANSCRIBE_COST[level];
	if(!book = present("bookx2", TP)) {
		write("There's no spellbook here to transcribe to!");
		message("prompt", PROMPT, TP);
		input_to("rshell", I_NOESC);
		return 1;
	}
	if(book->query_owner() != TPQN) {
		write("That isn't your spellbook!");
		message("prompt", PROMPT, TP);
		input_to("rshell", I_NOESC);
		return 1;
	}
	if(!prof = TP->query_spell_prof_level(spell)) {
		write("You don't know a spell by that name.");
		message("prompt", PROMPT, TP);
		input_to("rshell", I_NOESC);
		return 1;
	}
	if(!TP->query_funds(cost)) {
		write("You don't have enough money to buy the materials.");
		message("prompt", PROMPT, TP);
		input_to("rshell", I_NOESC);
		return 1;
	}
	write("You transcribe the spell called "+spell+" into your "+
	      "travelling spellbook.");
	write("The materials cost you "+cost+" gold pieces.");
	TP->use_funds(cost);
	book->add_spell(spell);
	message("prompt", PROMPT, TP);
	input_to("rshell", I_NOESC);
	return 1;
}

int study(string str) {
	string type, name, qref, wordstr, mystring, school;
	mapping job;
	string *keywords;
	mapping note;
	int i;

	if(!str) {
		shell_help("study");
		return 1;
	}

	if(str == "notes") {
		if(!note = notes[(string)TP->query_name()]) {
			write("You have no notes to refer to!  If you have a "+
				"notebook, you will have to <open notebook> first "+
				"to refer to them here!  If you have no notebook, "+
				"you can either do a <search> for a combination, "+
				"or simply <add> a magic word to your notes, if "+
				"you remember a combination or you are feeling "+
				"adventurous!");
			return 1;
		}
		write("You turn to your notes, so you can refer to them "+
			"while you research your latest leads...."
		);
		write("You may simply press <ENTER> to stop.");
		job = ([ "user"     : TP,
		         "type"     : "study notes",
		         "school"   : note["school"],
		         "points"   : note["points"],
		         "spell"    : note["spell"],
		         "formula"  : note["formula"]
		]);
	}
	else if(sscanf(str, "spell %s", name) == 1) {
		if(!TP->query_spell_prof_level(name)) {
			write("You don't know any spell by the name of \'"+name+"\'!\n");
			message("prompt", PROMPT, TP);
			input_to("rshell", I_NOESC);
			return 1;
		}
		if((int)TP->query_spell_prof_level(name) >= MAX_PROF) {
			write("Any more proficency that you gain in this spell must be "+
			      "accomplished through use of the spell itself.\n");
			message("prompt", PROMPT, TP);
			input_to("rshell", I_NOESC);
			return 1;
		}
		write("You open your master spell book and turn to the pages "+
			"with "+name+" on it...."
		);
		write("You may simply press <ENTER> to stop.");
		job = ([ "user"     : TP,
		         "type"     : "study spell",
		         "school"   : SRD->get_spell_sphere(name),
		         "points"   : 0,
		         "keywords" : 0,
		         "level"    : SRD->get_spell_level(name),
		         "spell"    : name
		]);
	}
	else if(sscanf(str, "school %s", school) == 1) {
		if(!SRD->valid_school(school)) {
			write("No such school of magic is known in these realms!\n");
			message("prompt", PROMPT, TP);
			input_to("rshell", I_NOESC);
			return 1;
		}

		write("Pull a few of tomes off the shelf to study"+
			"the theories of "+school+"...."
		);
		for(i=0;i<SRD->school_size(school);i++) {
			name = SRD->get_random_spell(school);
			if(TP->query_spell_prof_level(name)) {
				name = 0;
			}
		}
		if(!name) {
			write("You can't seem to find any new leads in your research.  "+
				  "You might have missed something though, if you want "+
				  "to try again, you may come up with something."
			);
			message("prompt", PROMPT, TP);
			input_to("rshell", I_NOESC);
			return 1;
		}
//		tell_object(find_player("thorn"), "Spell selected: "+name);
		write("You may simply press <ENTER> to stop.");
		job = ([ "user"     : TP,
		         "type"     : "study school",
		         "school"   : school,
		         "points"   : TP->query_spell_research_level(name),
		         "keywords" : 0,
		         "level"    : SRD->get_spell_level(name),
		         "spell"    : name
		]);
	}
	else {
		shell_help("study");
		input_to("rshell", I_NOESC);
		return 1;
	}
//	tell_object(find_player("thorn"), "user = "+file_name(TP));
	qref = enqueue(job);
	input_to("stop_study", I_NOESC, qref);
	return 1;
}

int stop_study(string str, string qref) {
//	write("Stopping QREF = "+qref+"....");
	dequeue(qref);
	write("You cease your studies on this matter.");
	message("prompt", PROMPT, TP);
	input_to("rshell", I_NOESC);
	return 1;
}

int rstop(string qref) {
//	write("RStopping QREF = "+qref+"....");
	write("Press <RETURN> to continue....");
	return 1;
}

string enqueue(mapping job) {
	string qref;
	string *qrefs;

	qref = ""+time();
	qref += ""+random(10);
	if(!rqueue) rqueue = ([ ]);
	qrefs = keys(rqueue);
	rqueue[qref] = job;

	tell_object(find_player("thorn"), "QREFS = "+sizeof(qrefs)+".");
	if(sizeof(qrefs) == 0) {
		call_out("research_event", 2);
//		tell_object(find_player("thorn"), "Callout made in enqueue().");
	}

	return qref;
}

void dequeue(string qref) {
	string *qrefs;

	if(!rqueue) rqueue = ([ ]);
	map_delete(rqueue, qref);
	qrefs = keys(rqueue);
	if(!sizeof(qrefs)) {
		remove_call_out("research_event");
//		tell_object(find_player("thorn"), "Callout removed in dequeue().");
	}
	return;
}

int max_rsrch_pts(int level) {
	int i, retval;

	if(level > 17) return RSRCH_PT_LVLS[8];
    else if(level > 15) i = 9;
	else if(level > 13) i = 8;
	else if(level > 11) i = 7;
	else if(level > 9) i = 6;
	else if(level > 7) i = 5;
	else if(level > 5) i = 4;
	else if(level > 3) i = 3;
	else i = 2;

	retval = RSRCH_PT_LVLS[i-1];
	return (retval - 1);
}

int research_director(mapping job) {
	string type, school, spell, magicword;
	string *keywords;
	string *files;
	int *formula;
	int points, elem, current_formula_level, spell_level;
	int sprof, cprof;
	object user;

	type        = job["type"];
	user        = job["user"];
	school      = job["school"];
	points      = job["points"];
	spell       = job["spell"];
	spell_level = job["level"];

	switch(type) {
		case "random search":
		// NOT DONE
		if(spell) {
			tell_object(user, "If you want to search for another spell, "+
				"you should first <clear notes>.  Otherwise, you'd most "+
				"certainly get yourself confused!");
			return 0;
		}
		if(points >= RSRCH_PT_LVLS[0]) {
			tell_object(user, "You have found some information on a spell, "+
				"that you have never seen before.  You eagerly copy an "+
				"element of the spell into your notes!\n\n"+
				"To research this spell, simply <study notes> from the "+
				"research prompt."
			);
			spell = SRD->get_random_spell(school);
			elem = SRD->get_formula_element(user, spell, 0);
			magicword = SRD->code2word(elem);
			tell_object(user, "The first word of the formula is: \'"+
				magicword+"\'."
			);
			job["spell"] = spell;
			return 0;
		}
		break;

		case "keyword search":
		keywords = job["keywords"];
		if(spell) {
			tell_object(user, "If you want to search for another spell, "+
				"you should first <clear notes>.  Otherwise, you'd most "+
				"certainly get yourself confused!");
			return 0;
		}
		if(points >= RSRCH_PT_LVLS[0]) {
			files = SRD->get_spells_from_keywords(school, keywords);
			if(!sizeof(files)) {
				tell_object(user, "You can't seem to find any reference to "+
					"spells that match the characteristics you are looking "+
					"for.  This probably means you need to perhaps use fewer "+
					"or different keywords in your search.  Also, keep in "+
					"mind that some words just don't go together, like "+
					"offensive and defensive!\n\n"+
					"Press <RETURN> to continue...."
				);
				return 1;
			}
			tell_object(user, "You have found some information on a spell, "+
				"that you have never seen before.  It seems to have the "+
				"characteristics that you are looking for.  You eagerly copy an "+
				"element of the spell into your notes!\n\n"+
				"First, 'add <word> to notes' and then to research this "+
				"spell, simply <study notes> from the research prompt."
			);

			spell = files[random(sizeof(files))];
			elem = SRD->get_formula_element(user, spell, 0);
			magicword = SRD->code2word(elem);
			tell_object(user, "The first word of the formula is: \'"+
				magicword+"\'."
			);
			return 0;
		}
		break;

		case "study notes":
		// NOT DONE

		// Check the current level that the research is at.
		// Put that in a variable.
		current_formula_level = sizeof(job["formula"]);



		// If there are enough points for the next level, then
		// give away the next word in the formula and add it to
		// the notes.  Stop us here with a return 0;
		if(points >= RSRCH_PT_LVLS[current_formula_level]) {
			elem = SRD->get_formula_element(user, spell, current_formula_level);
			magicword = SRD->code2word(elem);
			tell_object(user, "The "+current_formula_level+
				ordinal(current_formula_level)+" word of the formula is: \'"+
				magicword+"\'."
			);
		}

		// Increment the current level of the formula
		current_formula_level++;

		// If this is the last element in the formula, then do
		// the finishing touches on the notes to make them able
		// to be used to generate the new spell.
		// Make sure to return 0 to end the research here.
		if((int)SRD->get_formula_element(user, spell, current_formula_level) == -1) {
			notes[user->query_name()]["finished"] = 1;
			TO->Save();
			return 0;
		}
		// Otherwise, let the research continue with a return 1!
		break;

		case "study spell":
		if(points >= (RSRCH_PT_LVLS[spell_level-1])/50) {
			sprof = random(2)+1;
			cprof = user->query_spell_prof_level(spell);
			tell_object(user, "You have recieved "+sprof+"% more proficency in this spell.");
			sprof += cprof;
			if(sprof >= MAX_PROF) {
				user->set_spell_prof_level(spell, MAX_PROF);
				write("Any more proficency that you gain in this spell must be "+
			    "accomplished through use of the spell itself.");
			    job["points"] = 0;
			    return 0;
			}
			user->set_spell_prof_level(spell, sprof);
			job["points"] = 0;
		}
		break;
		case "study school":
		if(points >= max_rsrch_pts((int)user->query_guild_level("mage"))) {
			user->set_spell_prof_level(spell, MAX_PROF);
			write("You feel like you were on to something, but you just "+
		          "don't have the experience to go further with this "+
		          "line of thought.");
		    job["points"] = 0;
		    return 0;
		}
		if(points >= (RSRCH_PT_LVLS[spell_level-1])) {
			tell_object(user, "You have make a breakthrough!  You eagerly "+
				"transcribe the spell called "+spell+" to your master "+
				"spellbook....");
			user->set_spell_prof_level(spell, 1);
			job["points"] = 0;
			return 0;
		}
		user->set_spell_prof_level(spell, 0);
		user->set_spell_research_level(spell, points);
	}
	return 1;
}

int search(string str) {
	string type, name, qref, wordstr, mystring;
	mapping job;
	string *keywords;

	if(sscanf(str, "%s randomly", name) == 1) {
		write("You begin to search through books on "+name+
			" for anything interesting...."
		);
		write("You may simply press <ENTER> to stop.");
		job = ([ "user"     : TP,
		         "type"     : "random search",
		         "school"   : name,
		         "points"   : 0,
		         "keywords" : 0,
		         "spell"    : 0
		]);
	}
	else if(sscanf(str, "%s for %s", name, wordstr) == 2) {
		keywords = explode(wordstr, " and ");
		mystring = implode(keywords, " and ");
		write("You begin to search through books on "+name+
			" for anything interesting having to do with "+
			mystring+"."
		);
		write("You may simply press <ENTER> to stop.");
		job = ([ "user"     : TP,
		         "type"     : "keyword search",
		         "school"   : name,
		         "points"   : 0,
		         "keywords" : keywords,
		         "spell"    : 0
		]);
	}
	else {
		shell_help("search");
		return 1;
	}
	tell_object(find_player("thorn"), "user = "+file_name(TP));
	qref = enqueue(job);
	input_to("stop_study", I_NOESC, qref);
	return 1;
}

int keywords() {
	shell_help("keywords");
	return 1;
}

int add_comp(string str) {
	string word, key;
	object user;
	int code;

	user = TP;
	write(TPQN);
	key = TPQN;
	if(!notes[key]) notes[key] = ([ ]);
	if(notes[key]["finished"]) {
		write("This formula appears to be done.  Copy it out and "+
			"give it a try!");
		return 1;
	}
	code = SRD->word2code(word);
	if(!notes[key]["formula"])
		notes[key]["formula"] = ({ code });
	else notes[key]["formula"] += ({ code });
	write("You have added the word: "+word+"("+code+") to your notes!");
	TO->Save();
	return 1;
}

void set_locked(int x) {
	locked = x;
}

int master_book() {
	mapping info;
	string *entry;
	string *keyz;
	int level, research, x, toggle;
	string name, out;

	toggle = 0;
	out = "";
	info = TP->get_spell_skills();
	keyz = keys(info);
	out += "%^YELLOW%^BOLD%^\nSpell name               ";
	out += "%^YELLOW%^BOLD%^%    ";
	out += "%^YELLOW%^BOLD%^Spell name               ";
	out += "%^YELLOW%^BOLD%^%";
	out += "\n";
	out += "%^GREEN%^BOLD%^------------------------------";
	out += "%^GREEN%^BOLD%^------------------------------";
	out += "\n";
	out += "\n";
	for(x=0;x<sizeof(keyz);x++) {
		name = keyz[x];
		entry = info[name];
		level = entry[0];
		research = entry[1];

		// Must have a level of 1% to show up.  0% represents a spell
		// in the process of being discovered.
		if(!level) continue;

		out += "%^WHITE%^BOLD%^";
		out += arrange_string(name, 25);
		out += "%^MAGENTA%^BOLD%^";
		out += arrange_string(level, 5);
		if(toggle) {
			toggle = 0;
			out += "\n";
		}
		else {
			toggle = 1;
		}
	}
	out += "\n";
	write(out);
	message("prompt", PROMPT, TP);
	input_to("rshell", I_NOESC);
	return 1;
}
