#define ALL_LANGS ({"common","dwarvish","gnomish","goblin","kobold","orcish","halfling","drow","elven","undercommon","giant","beast"})

#define ANIMAL_LANGS ({ "sylvan" })

#define OLD_LANGS ({"firbolg","voadkyn","ogre-magi","hobgoblin","wemic","gnollish","beastman","bugbear","ogrish"})

// added - undercommon, giant, beast, as new languages. Nienne, 02/08.
// removed ogrish - moved ogres and ogre-magi to giant as per 3e standard. Nienne, 01/10.
// also note the #define above is repeated in /daemon/language_d instead of it using this file for some reason
// adding in some animal languages for use with shapeshifting and animals.  These don't behave exactly
// the same as standard languages, so they shouldn't be given to any races on character creation -Ares

#define LANGS ([\
   "dwarf":({"dwarvish","gnomish","halfling","orcish","goblin","undercommon"}),\
   "elf":({"elven","gnomish","halfling","orcish"}),\
   "gnome":({"gnomish","dwarvish","halfling","kobold","undercommon"}),\
   "half-elf":({"elven","gnomish","halfling","orcish","dwarvish"}),\
   "halfling":({"halfling","dwarvish","elven","gnomish"}),\
   "human":({"common","dwarvish","gnomish","orcish","halfling","elven","undercommon"}),\
   "beastman":({"beast","halfling","gnomish","orcish"}),\
   "bugbear":({"goblin","orcish"}),\
   "goblin":({"goblin","kobold","orcish"}),\
   "hobgoblin":({"goblin","orcish","kobold"}),\
   "kobold":({"kobold","goblin","orcish"}),\
   "half-ogre":({"giant","orcish","undercommon"}),\
   "ogre-mage":({"giant","orcish"}),\
   "orc":({"orcish","goblin","drow"}),\
   "half-orc":({"orcish","goblin","kobold","dwarvish","halfling"}),\
   "drow":({"drow","elven","goblin","gnomish","orcish"}),\
   "half-drow":({"drow","gnomish","goblin","orcish","elven","undercommon"}),\
   "firbolg":({"giant","orcish","dwarvish","goblin"}),\
   "gnoll":({"beast","orcish","goblin"}),\
   "ogre":({"giant","orcish"}),\
   "voadkyn":({"giant","elven"}),\
   "wemic":({"beast","dwarvish","orcish","giant"}),\
])