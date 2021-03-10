//	quest_ob.c
//	an inheritable quest object
//	written 151092 by Descartes of Borg

#include <std.h>

inherit OBJECT;

void set_quest_points(int x);
int query_quest_points();

int quest_points;

void set_quest_points(int x) { quest_points = x; }

int query_quest_points() { return quest_points; }

void clean_up() { return; }
