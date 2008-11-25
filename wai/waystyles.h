/**
  * WAI -- Where Am I?
  * Copyright (C) 2008 David Moreno Montero <monjemono@gmail.com>
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifndef WAYSTYLES_H
#define WAYSTYLES_H

#include <QBrush>
#include <QPen>
#include <QColor>

struct WayStyles{
    QBrush brush;
    QPen pen;
    bool drawBorder;
};

WayStyles wayStyles[256] = {
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 0
    { QBrush(QColor("#94D248"), Qt::SolidPattern), QPen(QBrush(QColor("#94D248")), 3, Qt::DotLine), false }, // 1 pedestrian
    { QBrush(QColor("#BF4141"), Qt::SolidPattern), QPen(QBrush(QColor("#BF4141")), 3, Qt::DotLine), false }, // 2 cycleway
    { QBrush(QColor("#3333AA"), Qt::SolidPattern), QPen(QBrush(QColor("#3333AA")), 4, Qt::DashLine), false }, // 3 steps
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 4
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 5
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 6
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 7
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 4), true }, // 8 residential +8
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 4), true }, // 9
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 6), true }, // 10
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 6), true }, // 11
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 8), true }, // 12
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 8), true }, // 13
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 10), true }, // 14
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 10), true }, // 15
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 6), false }, // 16 tertiary/road
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 6), false }, // 17
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 8), false }, // 18
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 10), false }, // 19
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 5), false }, // 20 // secondary
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 7), false }, // 21
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 7), false }, // 22
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 10), false }, // 23
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 3, Qt::DotLine), true }, // 24 train
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 25
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 26
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 27
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 28
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 29
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 30
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 31
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 8), false }, // 32 Primary, motorways
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 8), false }, // 33
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 10), false }, // 34
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 10), false }, // 35
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 12), false }, // 36
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 12), false }, // 37
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 15), false }, // 38
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 15), false }, // 39
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 3), false }, // 40 Service
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 3), false }, // 41
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 3), false }, // 42
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 4), false }, // 43
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 4), false }, // 44
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 5), false }, // 45
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 5), false }, // 46
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 5), false }, // 47
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 2), false }, // 48 Viaduct
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 3), false }, // 49
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 3), false }, // 50
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 4), false }, // 51
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 4), false }, // 52
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 5), false }, // 53
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 5), false }, // 54
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 5), false }, // 55
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 1), false }, // 56  // track
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 2), false }, // 57
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 3), false }, // 58
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 4), false }, // 59
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 60
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 61
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 62
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 63
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 64
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 65
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 66
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 67
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 68
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 69
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 70
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 71
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 72
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 73
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 74
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 75
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 76
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 77
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 78
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 79
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 80
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 81
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 82
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 83
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 84
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 85
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 86
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 87
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 88
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 89
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 90
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 91
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 92
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 93
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 94
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 95
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 96
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 97
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 98
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 99
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 100
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 101
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 102
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 103
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 104
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 105
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 106
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 107
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 108
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 109
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 110
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 111
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 112
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 113
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 114
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 115
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 116
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 117
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 118
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 119
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 120
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 121
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 122
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 123
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 124
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 125
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 126
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1), false }, // 127
    { QBrush(QColor("#CCCCCC"), Qt::SolidPattern), QPen(QBrush(QColor("#CCCCCC")), 1), false }, // 128 residential
    { QBrush(QColor("#7CE612"), Qt::SolidPattern), QPen(QBrush(QColor("#000000")), 1), false }, // 129 recreation ground
    { QBrush(QColor("#C5E677"), Qt::SolidPattern), QPen(QBrush(QColor("#000000")), 1), false }, // 130 park
    { QBrush(QColor("#E5F697"), Qt::SolidPattern), QPen(QBrush(QColor("#A9E694")), 1), false }, // 131 playground
    { QBrush(QColor("#A9E694"), Qt::SolidPattern), QPen(QBrush(QColor("#BF5BE6")), 1), false }, // 132 village green
    { QBrush(QColor("#BF5BE6"), Qt::SolidPattern), QPen(QBrush(QColor("#773377")), 1), false }, // 133 comercial
    { QBrush(QColor("#333377"), Qt::SolidPattern), QPen(QBrush(QColor("#333377")), 1), false }, // 134 industrial
    { QBrush(QColor("#442222"), Qt::SolidPattern), QPen(QBrush(QColor("#333333")), 1), false }, // 135 military
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 136
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 137
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 138
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 139
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 140
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 141
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 142
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 143
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 144
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 145
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 146
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 147
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 148
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 149
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 150
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 151
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 152
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 153
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 154
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 155
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 156
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 157
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 158
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 159
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 160
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 161
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 162
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 163
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 164
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 165
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 166
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 167
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 168
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 169
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 170
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 171
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 172
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 173
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 174
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 175
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 176
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 177
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 178
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 179
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 180
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 181
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 182
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 183
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 184
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 185
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 186
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 187
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 188
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 189
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 190
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 191
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 192
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 193
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 194
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 195
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 196
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 197
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 198
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 199
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 200
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 201
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 202
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 203
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 204
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 205
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 206
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 207
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 208
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 209
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 210
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 211
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 212
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 213
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 214
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 215
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 216
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 217
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 218
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 219
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 220
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 221
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 222
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 223
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 224
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 225
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 226
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 227
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 228
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 229
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 230
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 231
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 232
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 233
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 234
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 235
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 236
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 237
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 238
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 239
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 240
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 241
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 242
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 243
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 244
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 245
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 246
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 247
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 248
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 249
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 250
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 251
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 252
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 253
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1), false }, // 254
    { QBrush(QColor("#FF7777"), Qt::SolidPattern), QPen(QBrush(QColor("#FF7777")), 1), false } // 255
};

#endif // WAYSTYLES_H
