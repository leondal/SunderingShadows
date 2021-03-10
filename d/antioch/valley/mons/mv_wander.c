#include <std.h>
#include "../valley.h"
inherit MONSTER;

int count;

void create()
{
	::create();
	call_out("start_wonder",1);
}

void start_wonder()
{
	if(objectp(ETO))
		environment(TO)->init();
}

int test_heart()
{
	return 1;
}

void heart_beat()
{
	string *exits, exitn;
	int i,j;
	::heart_beat();
	if(!objectp(TO) || !objectp(ETO)) return;

	if(count > 20) {
		if((mixed *)TO->query_attackers() == ({ })) {
			if(objectp(environment(TO)))
			exits = environment(TO)->query_exits();
			i = sizeof(exits);
			if(exits && i) {
				j = random(i);
				exitn = (string)ETO->query_exit(exits[j]);
				if(exitn != ROOMS+"entrance" && exitn != ROOMS+"e1510" && exitn != ROOMS+"e1511" && exitn != ROOMS+"e1512" && exitn != ROOMS+"e1513" && exitn != ROOMS+"e1514" && exitn != ROOMS+"e1516" && exitn != ROOMS+"e1517" && exitn != ROOMS+"e1518" && exitn != ROOMS+"e1519" && exitn != ROOMS+"e1520" && exitn != ROOMS+"e1521" && exitn != ROOMS+"e1622" && exitn != ROOMS+"e1723" && exitn != ROOMS+"e1824" && exitn != ROOMS+"e1825" && exitn != ROOMS+"e1926" && exitn != ROOMS+"e2127" && exitn != ROOMS+"e2228" && exitn != ROOMS+"e2128" && exitn != ROOMS+"e2229" && exitn != ROOMS+"e2430" && exitn != ROOMS+"e2431" && exitn != ROOMS+"e2630" && exitn != ROOMS+"e2729" && exitn != ROOMS+"e2829" && exitn != ROOMS+"rb15" && exitn != ROOMS+"rb14" && exitn != ROOMS+"rb13" && exitn != ROOMS+"rb12" && exitn != ROOMS+"rb11" && exitn != ROOMS+"rb10" && exitn != ROOMS+"rb1" && exitn != ROOMS+"rb2" && exitn != ROOMS+"rb3" && exitn != ROOMS+"rb4" && exitn != ROOMS+"rb5" && exitn != ROOMS+"rb6" && exitn != ROOMS+"rb7" && exitn != ROOMS+"rb8" && exitn != ROOMS+"rb9" && exitn != ROOMS+"shore16" && exitn != ROOMS+"shore4" && exitn != ROOMS+"shore5" && exitn != ROOMS+"shore6" && exitn != ROOMS+"shore7" && exitn != ROOMS+"shore8" && exitn != ROOMS+"shore9" && exitn != ROOMS+"shore10" && exitn != ROOMS+"shore11" && exitn != ROOMS+"shore12" && exitn != ROOMS+"shore13" && exitn != ROOMS+"shore14" && exitn != ROOMS+"shore15" && exitn != FRING+"f1" && exitn != ROOMS+"e1611" && exitn != ROOMS+"e1710" && exitn != ROOMS+"e1809" && exitn != ROOMS+"e1908" && exitn != ROOMS+"e2007" && exitn != ROOMS+"e2106" && exitn != ROOMS+"e2205" && exitn != ROOMS+"e2304" && exitn != ROOMS+"e2403" && exitn != ROOMS+"e2502" && exitn != ROOMS+"e2603" && exitn != ROOMS+"e2704" && exitn != ROOMS+"e2706" && exitn != ROOMS+"e2707" && exitn != ROOMS+"e2806")
					TO->force_me(exits[j]);
			}
			count = 0;
		}
		count++;
	}
}
