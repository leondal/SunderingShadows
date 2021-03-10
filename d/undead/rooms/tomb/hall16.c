#include "../../undead.h"

inherit INH+"tomb_three.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :HALL+"hall17",
        "west"      :HALL+"hall15"
             ]));

}
