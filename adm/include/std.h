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
#define ROOM "/std/room"
#define HOTEL "/std/hotel"
#define DAEMON "/std/daemon"
#define BODY "/std/living/body"
#define SKILLS "/std/living/skills"
#define PIER "/std/pier"
#define VAULT "/std/vault"
#define WEAPON "/std/weapon"
#define THROWING_WEAPON "/std/throwing_weapon"
#define LRWEAPON "/std/lrweapon"
#define FIREARM "/std/firearm"
#define ARMOUR "/std/armour"
#define PARMOUR "/std/pocketarmour"
#define MATERIAL "/std/material"
#define BAG "/std/bag_logic"
#define BARKEEP "/std/barkeep"
#define BBOARD "/std/bboard"
#define CROOM "/std/controlroom"
#define FOOD "/std/food"
#define CVAULT "/std/controlvault"
#define RMONSTERS "/std/random_monsters"
#define LIBRARY "/std/library"
#define WATER "/std/water"
#define MOVE "/std/move"
#define GUILD "/std/guild"
#define DECAY "/std/decay"
#define POTION "/std/potion"
#define KIT "/d/common/obj/potion/_kit.c"
#define DOCK "/d/shadow/virtual/sea/dock"
#define ALIGN "/d/tharis/monsters/alignment_d"
#define STABLE "/std/stable"
#define HEALER "/std/healer"
#define TOWNSMAN "/std/townsman"
#define NPC "/std/npc"
#define GUARDSMAN "/std/guardsman.c"
#define SHAPESHIFT "/std/shapeshift.c"
#define TP this_player()
#define TPQCN this_player()->query_cap_name()
#define TPQN this_player()->query_name()
#define TOQCN this_object()->query_cap_name()
#define ETOQN environment(this_object())->query_name()
#define ETOQCN environment(this_object())->query_cap_name()
#define TPTN this_player()->query_true_name()
#define TPQTN this_player()->query_true_name()
#define TPQP this_player()->query_possessive()
#define TPQO this_player()->query_objective()
#define TPQS this_player()->query_subjective()
#define QP query_possessive()
#define QO query_objective()
#define QS query_subjective()
#define QNPC "/d/npc/QNPC.c"

#define ENV(A) environment(A)
#define FPL(A) find_player(A)
// because Garrett is silly and is a wabbit
#define SPELL "/std/magic/spell"
#define HEX "/std/magic/hex"
#define STATUS "/std/effect/status_eff"
#define DISEASE "/std/diseases/disease_obj"
#define FEAT "/std/feat"
#define SCRIBE "/std/scribe"
#define WEAPONLESS "/std/weaponless_monsters"
#define TO this_object()
#define WIZARDSPELL "/std/magic/wizardspell.c"
#define PO previous_object()
#define ETP environment(this_player())
#define ETO environment(this_object())
#define ROPE "/d/common/obj/misc/rope.c"
#define EETO environment(environment(this_object()))
#define QCN query_cap_name()
#define CHARACTER_LEVEL_CAP 50
#define TEST_CHARACTER_LEVEL_CAP 60

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

#define __COMBAT_SPEED__ 3

#define _TWO_WEEKS_IN_SECONDS_ 1209600
#define DEATH_FLAG_TIME 21600
#define PK_DEATH_FLAG_LOGIN_TIME 7200
#define PK_DEATH_RL_TIME 259200
#define SIZE_SMALL 1
#define SIZE_MEDIUM 2
#define SIZE_NORMAL 2
#define SIZE_LARGE 3
#define SIZE_GIANT 4
#define SIZE_UNIVERSAL -1
#define SIZEDTYPES ({"chain","clothing","leather","armour"})
#define MULTIPLE_WEAR ({"clothing","jewelry", "sheath"})
#define PK_DAMAGE_PERCENTAGE 100
