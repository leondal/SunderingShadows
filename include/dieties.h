/**
 * List of deities with follower-clergy pairs
 *
 * Followers must be two steps from god's alignment
 *
 * Clergy must be one step from god's alignment
 */
#define DIETIES (([\
   "callamir":({"Luck/Trickery",({1, 4, 5, 7, 8, 9}),({4, 7, 8})}),\
   "cevahir":({"War/Strategy",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}),\
   "jarmila":({"Light/Love",({1, 2, 4, 5, 6, 7, 8}),({1, 4, 5, 7})}),    \
   "khyron":({"Storms/Destruction",({3, 5, 6, 7, 8, 9}),({6, 8, 9})}), \
   "kismet":({"Magic/Knowledge",({1, 2, 3, 4, 5, 6, 8, 9}),({2, 4, 5, 6, 8})}), \
   "kreysneothosies":({"Justice/Protection",({1, 2, 3, 4, 5, 7}),({1, 2, 4})}), \
   "lord shadow":({"Darkness/Tyranny",({1, 2, 3, 5, 6, 9}),({2, 3, 6})}),\
   "lysara":({"Death/Fate",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}),\
   "nilith":({"Undead/War",({3, 5, 6, 7, 8, 9}),({6, 8, 9})}),\
   "nimnavanon":({"Forests/Weather",({1, 2, 3, 4, 5, 6, 7, 8, 9}),({2, 4, 5, 6, 8})}), \
   "seija":({"Magic/Knowledge",({1, 2, 3, 4, 5, 6, 8}),({1, 2, 3, 5})}),\
   "the faceless one":({"Murder/Deception",({2, 3, 4, 5, 6, 8, 9}),({3, 5, 6, 9})}),\
]))

#define PANTHEON DIETIES

#define PALADIN_GODS ({"jarmila", "kreysneothosies", "nilith", "lord shadow", "kismet", "lysara","cevahir","khyron","seija", "nimnavanon"})
