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
				if(exitn != ROOMS+"v51" && exitn != ROOMS+"v50" && exitn != ROOMS+"v44" && exitn != ROOMS+"v45" && exitn != ROOMS+"v46" && exitn != ROOMS+"v47" && exitn != ROOMS+"v48" && exitn != ROOMS+"v49" && exitn != ROOMS+"v52" && exitn != ROOMS+"v53" && exitn != ROOMS+"v54" && exitn != ROOMS+"v55" && exitn != ROOMS+"v56" && exitn != ROOMS+"v57" && exitn != ROOMS+"v60" && exitn != ROOMS+"v61" && exitn != ROOMS+"v58" && exitn != ROOMS+"v59" && exitn != ROOMS+"v62" && exitn != ROOMS+"v63" && exitn != ROOMS+"v64" && exitn != ROOMS+"v65" && exitn != ROOMS+"v66" && exitn != ROOMS+"v67" && exitn != ROOMS+"v68" && exitn != ROOMS+"v69" && exitn != ROOMS+"v70" && exitn != ROOMS+"v71" && exitn != ROOMS+"v72")
					TO->force_me(exits[j]);
			}
			count = 0;
		}
	count++;
	}
}
