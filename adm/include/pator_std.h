#include <terrain.h>
#define VENDOR "/std/vendor"
#define DRINK "/std/drink"
#define BANK "/std/bank"
#define ADMIN_BELL "/std/adm/admin_bell"
#define BOOK "/std/book"
#define OBJECT "/std/Object"
#define LIVING "/std/living"
#define MONSTER "/std/monster"
#define CONTAINER "/std/container"
#define ROOM "/std/pator_room"
#define HOTEL "/std/hotel"
#define DAEMON "/std/daemon"
#define BODY "/std/living/body"
#define SKILLS "/std/living/skills"
#define PIER "/std/pier"
#define VAULT "/std/vault"
#define WEAPON "/std/weapon"
#define THROWING_WEAPON "/std/throwing_weapon"
#define LRWEAPON "/std/lrweapon"
#define ARMOUR "/std/armour"
#define PARMOUR "/std/pocketarmour"
#define MATERIAL "/std/material"
#define BAG "/std/bag_logic"
#define BARKEEP "/std/barkeep"
#define BBOARD "/std/bboard"
#define CROOM "/std/controlroom"
#define CVAULT "/std/controlvault"
#define WATER "/std/water"
#define MOVE "/std/move"
#define GUILD "/std/guild"
#define DECAY "/std/decay"
#define POTION "/std/potion"
#define DOCK "/d/shadow/virtual/sea/dock"
#define ALIGN "/d/tharis/monsters/alignment_d"
#define STABLE "/std/stable"
#define HEALER "/std/healer"
#define TOWNSMAN "/std/townsman"
#define NPC "/std/npc"
#define TP this_player()
#define TPQCN this_player()->query_cap_name()
#define TPQN this_player()->query_name()
#define TOQCN this_object()->query_cap_name()
#define ETOQN environment(this_object())->query_name()
#define ETOQCN environment(this_object())->query_cap_name()
// because Garrett is a lazy conv-addicted crackhead.
#define SPELL "/std/magic/spell"
#define SCRIBE "/std/scribe"
#define WEAPONLESS "/std/weaponless_monsters"
#define TO this_object()
#define WIZARDSPELL "/std/magic/wizardspell.c"
#define TPTN this_player()->query_true_name()
#define TPQTN this_player()->query_true_name() 
#define PO previous_object()
#define ETP environment(this_player())
#define ETO environment(this_object())
#define ROPE "/d/common/obj/misc/rope.c"

#define VOTING "/std/voting"

#define VALID_BACKS ({ \
"human", \
"half-drow", \
"elf", \
"halfling",\
"kender",\
"gnome",\
"half-elf",\
"dwarf",\
"draconian",\
"thri-kreen",\
"wemic", \
"half-orc",\
"orc",\
"ogre",\
"half-ogre",\
"ogre-mage",\
"beastman",\
"bugbear",\
"firbolg",\
"giant", \
"troll",\
"titan",\
"voadkyn",\
"gnoll",\
"goblin",\
"hobgoblin",\
"kobold", \
"drow",\
"centaur",\
"merperson",\
"quadruped",\
"snake", \
"insectoid", \
"equine", \
"minotaur",\
"lizardman",\
})

