#define LEADER	"pontiac"

inherit "/std/Object";

string member;
mapping ideas;

void welcome();
string get_title(int pl_lev);
void guild_tell(string pre, string str);
void etre2(object tp);
void part2(object tp);
void part3(object tp);
int add_member(object who);

void init() {
    add_action("read","read");
    add_action("info","info");
    add_action("news","news");
    add_action("seekhome", "seekhome");
    add_action("set_philosophize","setphil");
    add_action("philosophize","philosophize");
    add_action("philosophize","phil");
    add_action("seekers","seekers");
    add_action("thinkto","thinkto");
    add_action("philemote","philemote");
    add_action("etre","be");
    add_action("power","power");
    add_action("relsoul","relsoul");
    add_action("soul","soul");
    if(!member) member = (string)this_player()->query_name();
    if((string)this_player()->query_name() != LEADER) return;
    add_action("enroll", "enroll");
    add_action("throw_out", "throw");
    add_action("newswrite", "newswrite");
    add_action("bring", "bring");
}

void init_arg(string *str) {
    if(!str) return;
    if(sizeof(str) < 5) return;
    ideas["text"] = ({ str[0], str[1], str[2] });
    ideas["delay"] = ({ str[3], str[4] });
    welcome();
    return;
}

void create() {
    seteuid(getuid());
    set_id( ({ "scroll", "nightmare_guild", "seeker_scroll" }) );
    set_long("An ancient scroll from the long lost library of Alexandria.\n"+
	"Only the Seekers of Truth hold these scrolls.\n"+
	"All Seekers should read their scrolls.\n"
    );
    set_weight(0);
    set_value(0);
    ideas = ([ "delay":({}), "text": ({}) ]);
    ideas["delay"] = ({2, 2});
    ideas["text"] = ({
	this_player()->query_cap_name()+" gets an idea.",
	this_player()->query_cap_name()+" looks to the sky.",
	this_player()->query_cap_name()+" doubts "+this_player()->query_possessive()+" own existence."
    });
    member = 0;
}

string query_short() {
    return member + "'s Scroll of Knowledge";
}

void extra_look() {
    write(member+" is a Seeker of Truth.\n");
}
void welcome() {
    write("\n");
    write("Welcome Philosopher!\n");
    write("For a list of abilities: <info truth>\n");
    write("For the latest word on the truth: <news truth>\n");
    write("\n");
    say(this_player()->query_cap_name()+" resumes "+this_player()->query_possessive()+" search for the Truth.\n");
    member = capitalize((string)this_player()->query_name());
}


int news(string str) {
    if(!str || str != "truth") return 0;
    cat("/realms/descartes/guild/news/news");
    return 1;
}

int info(string str) {
    if(!str || str != "truth") return 0;
    this_player()->more("/realms/descartes/guild/news/info");
    return 1;
}

int seekers() {
    int x, y;
    object *who;

    x = sizeof(users());
    who = users();
    write("These philosophers are currently in search of the Truth:\n\n");
    for(y=0; y<x; y++) {
	if(present("seeker_scroll", who[y])) {
	    if(!who[y]->query_invis()) {
		write(who[y]->query_short()+"\n");
 	    }
	}
    }
    write("\nMay we all be one with the Truth!\n");
    return 1;
}

int philemote(string str) {
    if(!str) {
	notify_fail("Don't do much of it, eh?\n");
	return 0;
    }
    guild_tell("-> Philosopher "+this_player()->query_cap_name(), str);
    return 1;
}

int thinkto(string str) {
    string whom, what;

    if(!str) {
	notify_fail("Not feeling talkative?\n");
	return 0;
    }
    if(sscanf(str, "%s %s", whom, what) != 2) return 0;
    if(!find_living(whom)) {
	notify_fail("No such seeker on line now.\n");
	return 0;
    }
    if(!present("seeker_scroll", find_living(whom))) {
	notify_fail(capitalize(whom)+" does not seek the Truth.\n");
	return 0;
    }
    if(find_living(whom)->query_blocked("philosopher")) {
	write("The philosopher you seek is blocking out other thoughts.\n");
	return 1;
    }
    tell_object(find_living(whom), "Philosopher "+this_player()->query_cap_name()+" thinks to you: "+what+"\n");
    write("You think to philosopher "+capitalize(whom)+": "+what+"\n");
    return 1;
}

void guild_tell(string pre, string str) {
    object *who;
    int x, y;

    x = sizeof(users());
    who = allocate(x);
    who = users();
    for(y=0; y<x; y++) {
	if(present("seeker_scroll", who[y])) {
	    if(!who[y]->query_blocked("philosopher")) {
	    tell_object(who[y], pre+" "+str+"\n");
	    }
	}
    }
    return;
}


int read(string str) {
    if(!str || str != "scroll") return 0;
    write("As a philosopher of the Seekers of Truth, you have been given this scroll\n");
    write("from the ancient and lost library of Alexandria.  The information it\n");
    write("contains is meant to help you in your search for the Truth.  Good Luck.\n");
    write("<info truth> will tell you more, as will <news truth>\n");
    return 1;
}

int etre() {
    write("You think...\n");
    say(this_player()->query_cap_name()+" thinks.\n");
    call_out("etre2",3, this_player());
    return 1;
}

void etre2(object tp) {
    write("...and suddenly you are!\n");
    say("And suddenly Philosopher "+tp->query_cap_name()+" Is.\n", tp);
    return;
}

int soul(string str) {
    object ob;
    int al;
    string cap_name;

    if(!str) {
	notify_fail("If it might exist, then it is not in this possible world.\n");
	return 0;
    }
    ob = present(str, environment(this_player()));
    cap_name = (string)ob->query_cap_name();
    if(!ob) {
	notify_fail("If it might exist, then it is not in this possible world.\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail("That is not a living thing!\n");
	return 0;
    }
    this_player()->add_mp(-5);
    al = (int)ob->query_alignment();
    say(this_player()->query_cap_name()+" uses "+this_player()->query_possessive()+" knowledge to determine "+capitalize(str)+"'s Truth.\n");
    if(al>1000) write(cap_name+"'s Truth is among the most pure and pious of existant beings.\n");
    else if(al>700) write(cap_name+"'s Truth is most certainly that of holiness.\n");
    else if(al>250) write(cap_name+"'s Truth is in goodness.\n");
    else if(al>70) write(cap_name+"'s Truth is partially in goodness.\n");
    else if(al>-70) write(cap_name+" has no Truth to "+ob->query_objective()+".\n");
    else if(al>-250) write(cap_name+"'s Truth is partially in the way of malice.\n");
    else if(al>-700) write(cap_name+"'s Truth is in the way of malice.\n");
    else if(al>-1000) write(cap_name+"'s Truth is most certainly in the way of evil.\n");
    else write(cap_name+"'s Truth is among the most wicked and evil of existant beings.\n");
    return 1;
}

int power(string str) {
    int targ_level, pl_level, diff;
    object ob, tp;
    string cap_name;

    tp = this_player();
    if(!str) {
	notify_fail("The power of nothingness amazes you.\n");
	return 0;
    }
    cap_name = capitalize(str);
    ob = present(str, environment(tp));
    if(!ob) {
	notify_fail("That does not exist as such.\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail("Only living things have the power you seek.\n");
	return 0;
    }
    say(tp->query_cap_name()+" uses "+tp->query_possessive()+" knowledge to assess "+cap_name+"'s relative power.\n");
    targ_level = (int)ob->query_level();
    pl_level = (int)tp->query_level();
    diff = targ_level - pl_level;
    if(diff>20) write("This being is more powerful than you can imagine.\n");
    else if(diff>15) write("This being is unbelievably more powerful than you.\n");
    else if(diff>10) write("This being is much more powerful than you.\n");
    else if(diff>7) write("This being is more powerful than you.\n");
    else if(diff>4) write("This is a stronger being.\n");
    else if(diff>1) write("This being is vaguely more powerful than you.\n");
    else if(diff>-1) write("This being shares your power.\n");
    else if(diff>-4) write("This being is vaguely less powerful than you.\n");
    else if(diff>-7) write("This is a weaker being.\n");
    else if(diff>-10) write("This being is much less powerful than you.\n");
    else write("This being would most definitely appreciate your benevolence.\n");
    tp->add_mp(-5);
    return 1;
}

mixed *query_auto_load() {
    return ({ "/realms/descartes/guild/object/seeker_scroll",
      ({ ideas["text"][0], ideas["text"][1], ideas["text"][2], ideas["delay"][0], ideas["delay"][1] }) });
}

int get() {
    return 0;
}

int drop() {
    return 1;
}

string get_title(int pl_lev) {
    if(pl_lev<5) return ("Apprentice");
    else if(pl_lev<9) return ("Student");
    else if(pl_lev<13) return ("Thinker");
    else if(pl_lev<17) return ("Philosopher");
    else if(pl_lev<19) return ("Low Saint");
    else if(pl_lev==19) return ("High Saint");
    else return "High Mortal Saint";
}

int philosophize() {
    write("Idea 1.\n");
    say("*"+ideas["text"][0]+"\n", this_player());
    call_out("part2", ideas["delay"][0], this_player());
    return 1;
}

void part2(object tp) {
    write("Idea 2.\n");
    say("*"+ideas["text"][1]+"\n", this_player());
    call_out("part3", ideas["delay"][1], tp);
    return;
}

void part3(object tp) {
    write("Idea 3.\n");
    say("*"+ideas["text"][2]+"\n", tp);
    return;
}

int set_philosophize(string str) {
    string what, new_str;
    int which, delay;

    if(!str) {
	write("No string.  Philosophizing unchanged.\n");
	return 1;
    }
    if(sscanf(str, "%s %d %s", what, which, new_str) !=3) {
	write("Syntax incorrect.  Nothing changed.\n");
	return 1;
    }
    else {
	if(what=="delay") {
	  if(sscanf(new_str, "%d", delay) != 1) {
	    write("You must enter an integer as your time argument.\n");
	    return 1;
	  }
 	  else {
	    if(which != 1 && which != 2) {
		write("There are only two delays.\n");
		return 1;
	    }
	    ideas["delay"][which-1] = delay;
	  }
	}
	else if(what == "idea") {
	    if(which != 1 && which !=2 && which != 3) {
		write("Which idea is that?\n");
	    }
	    else ideas["text"][which-1] = new_str;
	}
    }
    return 1;
}

int enroll(string str) {
    object who;

    if(!str) {
	notify_fail("Enroll whom "+capitalize(LEADER)+"\n");
	return 0;
    }
    if(!(who = present(str, environment(this_player())))) {
	notify_fail("That person is not here!\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 200) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!add_member(who)) {
	write("That person may not join the Seekers of Truth.\n");
	return 1;
    }
    this_player()->add_mp(-200);
    write(who->query_cap_name()+" is now a member of the Seekers of Truth.\n");
    tell_object(who, "You are now a Seeker of Truth.\n");
    return 1;
}

int add_member(object who) {
    object ob;

    if((string)who->query_class() == "rogue") {
	write("No rogues! Please!\n");
	return 0;
    }
    if((int)who->query_stats("intelligence") < 13) {
	write("Bah! That person is too stupid to think.\n");
	return 0;
    }
    if(who->query_guild()) {
	write(who->query_cap_name()+" is already a member of a guild!\n");
	return 0;
    }
    who->set_guild("philosopher");
    who->setenv("start", "/realms/descartes/guild/room/phil_lounge");
    ob = new("/realms/descartes/guild/object/seeker_scroll");
    ob->move(who);
    return 1;
}

int throw_out(string str) {
    object ob;

    if(!str) {
	notify_fail("Throw whom out?\n");
	return 0;
    }
    if(sscanf(str, "%s %*s", str) != 1) {
	notify_fail("<throw [whom] out>\n");
	return 0;
    }
    if(!(ob = find_player(lower_case(str)))) {
	notify_fail("That player is not on the mud right now.\n");
	return 0;
    }
    if((string)ob->query_guild() != "philosopher") {
	notify_fail("That person is not a philosopher!\n");
	return 0;
    }
    ob->set_guild(0);
    if(present("seeker_scroll", ob))
	present("seeker_scroll", ob)->remove();
    write("You throw "+ob->query_cap_name()+" out of the Seekers of Truth.\n");
    tell_object(ob, capitalize(LEADER)+" has removed you from the Seekers of Truth.\n");
    return 1;
}

int bring(string str) {
    object who;

    if(!str) {
	notify_fail("Bring whom?\n");
	return 0;
    }
    who = find_player(lower_case(str));
    if(!who) {
	notify_fail("That person is not in our reality.\n");
	return 0;
    }
    if((string)who->query_guild() != "philosopher") {
	notify_fail(capitalize(str)+" is not a Seeker!\n");
	return 0;
    }
    if(environment(who)->query_property("no teleport")) {
	notify_fail("A magic force blocks your powers.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no teleport")) {
	notify_fail("A magic force blocks your powers.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("A magic force blocks your powers.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 70) {
	notify_fail("Too low on magic power,\n");
	return 0;
    }
    this_player()->add_mp(-70);
    who->move(environment(this_player()));
    who->describe_current_room(1);
   return 1;
}

int seekhome(string str) {
    if(this_player()->query_mp() < 50) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no teleport")) {
        notify_fail("A magic force prevents your teleportation.\n");
        return 0;
    }
    this_player()->move_player("/realms/descartes/guild/room/phil_lounge");
    this_player()->add_mp(-150);
/* Yes, this code intentionally allows negative exp on a player */
    return 1;
}

int newswrite(string str) {
    if((string)this_player()->query_name() != LEADER) return 0;
    write("Now rewriting philosopher news.\n");
    this_player()->edit("/tmp/phil_news", "end_news", this_object());
    return 1;
}

void end_news() {
    rm("/realms/descartes/guild/news/news");
    write_file("/realms/descartes/guild/news/news", read_file("/tmp/phil_news"));
    rm("/tmp_phil_news");
    write("News news in effect.\n");
}

void abort() {
    rm("/tmp/phil_news");
}
