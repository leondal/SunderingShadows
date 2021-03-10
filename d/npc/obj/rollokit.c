#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id( ({"tailors kit", "kit" }) );
    set_name("tailor's kit");
    set("short", "A tailor's tool kit");
    set_long(
@THORN
This contains the pins, needles, spools of thread and patches that
a tailor would use to do his work.
THORN
    );
    set_weight(0);
    set_value(0);
}

void init() {
    ::init();
	add_action("start_func", "letsdoit");
 	add_action("wait_for", "waitfor");
 	add_action("dye_func", "dyeitbaby");
	add_action("get_func", "gogeta");
 	add_action("done_func", "rocknroll");
 	add_action("nodye_func", "nodye");
 	add_action("sew_func", "sewwhat");
 	add_action("thread_func", "threadof");
 	add_action("next_func", "nextemblem");
}

int working_for(string str) {
	ETO->working_for(str);
	return 1;
}

int give_up() {
	ETO->give_up();
	return 1;
}

int start_func(string player) {
	ETO->start_func(player);
	return 1;
}

int waitfor(string time) {
	ETO->waitfor(time);
	return 1;
}

int get_func(string item) {
	ETO->get_func(item);
	return 1;
}


int dye_func(string color) {
	ETO->dye_func(color);
	return 1;
}

int done_func() {
	ETO->done_func();
	return 1;
}

void nodye_func() {
	ETO->nodye_func();
	return 1;
}

void sew_func(string emb) {
	ETO->sew_func(emb);
	return 1;
}

int thread_func(string color) {
	ETO->thread_func(color);
	return 1;
}

int next_func() {
	ETO->next_func();
	return 1;
}
