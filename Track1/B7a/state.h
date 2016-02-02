/*
* state.h
*
* Created: 2-2-2016 16:36:56
*  Author: mauro
*/


#ifndef STATE_H_
#define STATE_H_

/* An incomplete type for the state representation itself */
typedef struct start,s1,s2,s3,end;

/* Function pointer to the implementation of the interface */
typedef void (*event_start_func_f)(watch_state_t *sw);
typedef void (*event_stop_func_f)(watch_state_t *sw);
typedef void (*event_split_func_f)(watch_state_t *sw);

typedef enum states_tag states_e;
enum states_tag { START, S1, S2, S3, END };

struct tag_watch_state {
	/* Events */
	event_start_func_f start;
	event_split_func_f split;
	event_stop_func_f stop;

	/* States */
	states_e current_state;

	int time;
};

void initialize(watch_state_t *state);
char* state_to_string(states_e state);




#endif /* STATE_H_ */