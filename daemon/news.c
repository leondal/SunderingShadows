//	/adm/daemon/news_d.c
//	from the Nightmare mudlib
//	a news daemon for logging in
//	created by Descartes of Borg 13 february 1993
//      check added by Pallando, 29 january 1994

#include <news.h>

void read_news();
void class_news();
void high_mortal_news();
void immortal_news();
void arch_news();
void end_news();

void create() { seteuid(getuid()); }

void read_news() {
    if(file_size(NEWS) == (int)this_player()->query_news("general")) {
	class_news();
	return;
    }
    this_player()->set_news("general", file_size(NEWS));
    tell_object(this_player(), "\nGeneral news:\n");
    if(file_exists(NEWS))
      message("info", read_file(NEWS), this_player());
    tell_object(this_player(), "Press <return> to continue: ");
    input_to("class_news");
}

void class_news() {
    string *cl;
    int i;

    cl = (string *)this_player()->query_classes();
     if(!cl || cl == ({})) cl = ({"child"});
    for(i=0;i<sizeof(cl);i++){
    	if(file_size(NEWS_DIR+cl[i]) != (int)this_player()->query_news(cl[i])) {
    		this_player()->set_news(cl[i], file_size(NEWS_DIR+cl[i]));
    		if(cl[i] == "child") tell_object(this_player(), "New player news:\n");
    		else tell_object(this_player(), "\n"+capitalize(cl[i])+" news:\n");
    		if(file_exists(NEWS_DIR+cl[i]))
      			message("info", read_file(NEWS_DIR+cl[i]), this_player());
    		tell_object(this_player(), "Press <return> to continue: ");
    		input_to("class_news");
    		return;
    	}
    }
	high_mortal_news();
	return;
    
}

void high_mortal_news() {
    if(!high_mortalp(this_player()) ||
      file_size(HIGH_MORTAL_NEWS) == (int)this_player()->query_news("high mortal")) {
	immortal_news();
	return;
    }
    this_player()->set_news("high mortal", file_size(HIGH_MORTAL_NEWS));
    tell_object(this_player(), "\nHigh mortal news:\n");
    if(file_exists(HIGH_MORTAL_NEWS))
      message("info", read_file(HIGH_MORTAL_NEWS), this_player());
    input_to("immortal_news");
}

void immortal_news() {
    if(!wizardp(this_player()) ||
      file_size(IMMORTAL_NEWS) == (int)this_player()->query_news("immortal")) {
	    arch_news();
	    return;
    }
    this_player()->set_news("immortal", file_size(IMMORTAL_NEWS));
    tell_object(this_player(), "\nImmortal news:\n");
    if(file_exists(IMMORTAL_NEWS))
      message("info", read_file(IMMORTAL_NEWS), this_player());
    tell_object(this_player(), "Press <return> to continue: ");
    input_to("arch_news");
}

void arch_news() {
    if(!archp(this_player()) || (file_size(ARCH_NEWS) == -1) ||
      file_size(ARCH_NEWS) == (int)this_player()->query_news("arch")) {
        end_news();
	return;
    }
    this_player()->set_news("arch", file_size(ARCH_NEWS));
    tell_object(this_player(), "\Arch news:\n");
    if(file_exists(ARCH_NEWS))
      message("info", read_file(ARCH_NEWS), this_player());
    message("prompt", "Press <return> to continue: ", this_player());
    input_to("end_news");
}

void end_news() { this_player()->describe_current_room(1); }
