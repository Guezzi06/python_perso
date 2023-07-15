/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_chllg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:19:52 by aguezzi           #+#    #+#             */
/*   Updated: 2022/12/08 22:20:07 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import sys
import math
from numpy import zeros,array

base_x, base_y = [int(i) for i in input().split()]
heroes_per_player = int(input())  # Always 3

# game loop
while True:

    my_health, my_mana = [int(j) for j in input().split()]
    enemy_health, enemy_mana = [int(j) for j in input().split()]
    entity_count = int(input())  # Amount of heros and monsters you can see
    min = 100000
    monster_x_most_dangerous = 0
    monster_y_most_dangerous = 0
    heros_x = array([0, 0, 0])
    heros_y = array([0, 0, 0])
    a = 0
    for i in range(entity_count):
        # _id: Unique identifier
        # _type: 0=monster, 1=your hero, 2=opponent hero
        # x: Position of this entity
        # shield_life: Ignore for this league; Count down until shield spell fades
        # is_controlled: Ignore for this league; Equals 1 when this entity is under a control spell
        # health: Remaining health of this monster
        # vx: Trajectory of this monster
        # near_base: 0=monster with no target yet, 1=monster targeting a base
        # threat_for: Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
        id_, type_, x, y, shield_life, is_controlled, health, vx, vy, near_base, threat_for = [int(j) for j in input().split()]
        if type_ == 0:
            dist = math.sqrt((x+vx - base_x)*(x+vx - base_x) + (y+vy - base_y)*(y+vy - base_y))
            print(dist, file=sys.stderr)
            if dist < min:
                monster_x_most_dangerous = x+vx
                monster_y_most_dangerous = y+vy
                min = dist
        if type_ == 1:
            heros_x[a] = x
            heros_y[a] = y
            a+=1
    print(min, monster_x_most_dangerous, monster_y_most_dangerous, file=sys.stderr)
    for i in range(heroes_per_player):
        if min < 3000:
            if i == 2:
                if (my_mana >= 10) & (min <= 600):
                    print("SPELL WIND", abs(base_x - 15000), abs(base_y - 1000))
                else:
                    print("MOVE ", abs(base_x - 1000), abs(base_y - 500))
            else:
                print("MOVE", monster_x_most_dangerous, monster_y_most_dangerous)
        elif i == 0:
            print("MOVE", abs(base_x - 5000), abs(base_y - 1500))
        elif i == 1:
            print("MOVE", abs(base_x - 3250), abs(base_y - 3250))
        elif i == 2:
            print("MOVE", abs(base_x - 1000), abs(base_y - 500))

import sys
import math

base_x, base_y = [int(i) for i in input().split()]
heroes_per_player = int(input())  # Always 3

def mode_explorer(my_heroes, monsters, monster_x_most_dangerous, monster_y_most_dangerous):
    a = 0
    b = 0
    for i in monsters:
        if math.sqrt((my_heroes[0]['x'] -i['x'])*(my_heroes[0]['x'] -i['x']) + (my_heroes[0]['y'] -i['y'])*(my_heroes[0]['y'] -i['y'])) <= 2200:
            print("MOVE", i['x'] + i['vx'], i['y'] + i['vy'])
            a+=1
            break
    for i in monsters:
        if math.sqrt((my_heroes[1]['x'] -i['x'])*(my_heroes[1]['x'] -i['x']) + (my_heroes[1]['y'] -i['y'])*(my_heroes[1]['y'] -i['y'])) <= 2200:
            print("MOVE", i['x'] + i['vx'], i['y'] + i['vy'])
            b+=1
            break
    if a == 0:
        print("MOVE", monster_x_most_dangerous, monster_y_most_dangerous)
    if b == 0:
        print("MOVE", monster_x_most_dangerous, monster_y_most_dangerous)

# game loop
while True:

    my_health, my_mana = [int(j) for j in input().split()]
    enemy_health, enemy_mana = [int(j) for j in input().split()]
    entity_count = int(input())  # Amount of heros and monsters you can see
    min = 100000
    monster_x_most_dangerous = 0
    monster_y_most_dangerous = 0
    my_heroes = []
    enemy_heroes = []
    monsters = []
    a = 0
    for i in range(entity_count):
        # _id: Unique identifier
        # _type: 0=monster, 1=your hero, 2=opponent hero
        # x: Position of this entity
        # shield_life: Ignore for this league; Count down until shield spell fades
        # is_controlled: Ignore for this league; Equals 1 when this entity is under a control spell
        # health: Remaining health of this monster
        # vx: Trajectory of this monster
        # near_base: 0=monster with no target yet, 1=monster targeting a base
        # threat_for: Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
        id_, type_, x, y, shield_life, is_controlled, health, vx, vy, near_base, threat_for = [int(j) for j in input().split()]
        entity = {
            'id':id_,
            'type':type_,
            'x':x,
            'y':y,
            'shield_life':shield_life,
            'is_controlled':is_controlled,
            'health':health,
            'vx':vx,
            'vy':vy,
            'near_base':near_base,
            'threat_for':threat_for
        }
        if type_ == 0:
            monsters.append(entity)
        elif type_ == 1:
            my_heroes.append(entity)
        elif type_ == 2:
            enemy_heroes.append(entity)
        if type_ == 0:
            dist = math.sqrt((x+vx - base_x)*(x+vx - base_x) + (y+vy - base_y)*(y+vy - base_y))
            print(dist, file=sys.stderr)
            if dist < min:
                monster_x_most_dangerous = x+vx
                monster_y_most_dangerous = y+vy
                min = dist
    print(min, monster_x_most_dangerous, monster_y_most_dangerous, file=sys.stderr)
    for i in range(heroes_per_player):
        if min < 3000:
            if i == 2:
                if (my_mana >= 10) & (min <= 600):
                    print("SPELL WIND", abs(base_x - 15000), abs(base_y - 1000))
                else:
                    print("MOVE", abs(base_x - 1000), abs(base_y - 500))
            else:
                if (my_mana <= 40) & (min <= 1200):
                    print("MOVE", monster_x_most_dangerous, monster_y_most_dangerous)
                else:
                    mode_explorer(my_heroes, monsters, monster_x_most_dangerous, monster_y_most_dangerous)
        elif i == 0:
            mode_explorer(my_heroes, monsters, monster_x_most_dangerous, monster_y_most_dangerous)
        elif i == 1:
            mode_explorer(my_heroes, monsters, monster_x_most_dangerous, monster_y_most_dangerous)
        elif i == 2:
            print("MOVE", abs(base_x - 1000), abs(base_y - 500))
