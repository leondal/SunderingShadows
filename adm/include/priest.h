#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;
#define YOU CASTER->query_cap_name()
#define HIM TARGET->query_cap_name()
#define OBJ TARGET->query_objective()

#define MINE	CASTER->query_possessive()
#define HIS	TARGET->query_possessive()
#define MY_PERS	CASTER->query_subjective()
#define YOUR_PERS	TARGET->query_subjective()
#define HERE	PLACE

#define caster CASTER
#define target TARGET
