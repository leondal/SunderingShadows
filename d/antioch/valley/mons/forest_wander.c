#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

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
				if(exitn != ROOMS+"entrance" && exitn != ROOMS+"orccave" && exitn != ROOMS+"e1523" && exitn != "/d/antioch/wild/forest/trail6" && exitn != ROOMS+"spider1" && exitn != ROOMS+"ogrecamp")
					TO->force_me(exits[j]);

			}
			count = 0;
		}
		count++;
	}
}
