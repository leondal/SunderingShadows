//#ifndef __stealth.h__
//#define __stealth.h__
#ifndef STEALTHH
#define STEALTHH
#define STEALTH_MOD(play, variable, area)    if(sizeof(play->query_armour(area))) variable += play->skill_armor_mod(play->query_armour(area));

#endif
//#endif  //__stealth.h__
