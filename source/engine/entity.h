#ifndef ENTITY_H
#define ENTITY_H

typedef struct Entity
{
    unsigned int id;
    unsigned int componentMask;
} Entity;


void addEntity(struct Entity *entity);

#endif // ENTITY_H
