#ifndef EVENT_HANDLER_H
# define EVENT_HANDLER_H

# include "wg_vars.h"
# include "dynamicList.h"

typedef struct s_event {
    int keycode;
    void (*action)(void *content, Game *game);
    void *linkedContent;
} Event;

typedef struct s_eventhandler {
    DList *events;
} EventHandler;

Event *eventConstructor(int keycode, void (*action)(void *content, Game *game), void *linkedContent);
void freeEvent(Event *e);

EventHandler *initEventHandler();
void addEventToEventHandler(EventHandler *eh, Event *e);
void callEvents(EventHandler *eh, int keycode, Game *game);

#endif