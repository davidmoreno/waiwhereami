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
};

WayStyles wayStyles[256] = {
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 0
    { QBrush(QColor("#94D248"), Qt::SolidPattern), QPen(QBrush(QColor("#94D248")), 3) }, // 1 pedestrian
    { QBrush(QColor("#BF4141"), Qt::SolidPattern), QPen(QBrush(QColor("#BF4141")), 3) }, // 2 cycleway
    { QBrush(QColor("#3333AA"), Qt::SolidPattern), QPen(QBrush(QColor("#3333AA")), 4) }, // 3 steps
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 4
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 5
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 6
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 7
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 4) }, // 8 residential +8
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 4) }, // 9
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 6) }, // 10
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 6) }, // 11
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 8) }, // 12
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 8) }, // 13
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 10) }, // 14
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 10) }, // 15
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 6) }, // 16 tertiary/road
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 6) }, // 17
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 8) }, // 18
    { QBrush(QColor("#ECF316"), Qt::SolidPattern), QPen(QBrush(QColor("#ECF316")), 10) }, // 19
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 5) }, // 20 // secondary
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 7) }, // 21
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 7) }, // 22
    { QBrush(QColor("#2CD316"), Qt::SolidPattern), QPen(QBrush(QColor("#2CD316")), 10) }, // 23
    { QBrush(QColor("#FFFFFF"), Qt::SolidPattern), QPen(QBrush(QColor("#FFFFFF")), 3, Qt::DotLine) }, // 24 train
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 25
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 26
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 27
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 28
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 29
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 30
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 31
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 8) }, // 32 Primary, motorways
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 8) }, // 33
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 10) }, // 34
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 10) }, // 35
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 12) }, // 36
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 12) }, // 37
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 15) }, // 38
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 15) }, // 39
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 3) }, // 40 Service
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 3) }, // 41
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 3) }, // 42
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 4) }, // 43
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 4) }, // 44
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 5) }, // 45
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 5) }, // 46
    { QBrush(QColor("#1251C5"), Qt::SolidPattern), QPen(QBrush(QColor("#1251C5")), 5) }, // 47
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 2) }, // 48 Viaduct
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 3) }, // 49
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 3) }, // 50
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 4) }, // 51
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 4) }, // 52
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 5) }, // 53
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 5) }, // 54
    { QBrush(QColor("#7777AA"), Qt::SolidPattern), QPen(QBrush(QColor("#7777AA")), 5) }, // 55
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 1) }, // 56  // track
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 2) }, // 57
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 3) }, // 58
    { QBrush(QColor("#BF8F15"), Qt::SolidPattern), QPen(QBrush(QColor("#BF8F15")), 4) }, // 59
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 60
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 61
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 62
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 63
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 64
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 65
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 66
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 67
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 68
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 69
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 70
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 71
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 72
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 73
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 74
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 75
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 76
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 77
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 78
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 79
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 80
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 81
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 82
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 83
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 84
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 85
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 86
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 87
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 88
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 89
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 90
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 91
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 92
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 93
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 94
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 95
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 96
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 97
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 98
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 99
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 100
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 101
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 102
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 103
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 104
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 105
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 106
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 107
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 108
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 109
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 110
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 111
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 112
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 113
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 114
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 115
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 116
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 117
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 118
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 119
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 120
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 121
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 122
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 123
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 124
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 125
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 126
    { QBrush(QColor("#773333"), Qt::SolidPattern), QPen(QBrush(QColor("#773333")), 1) }, // 127
    { QBrush(QColor("#CCCCCC"), Qt::SolidPattern), QPen(QBrush(QColor("#CCCCCC")), 1) }, // 128 residential
    { QBrush(QColor("#7CE612"), Qt::SolidPattern), QPen(QBrush(QColor("#7CE612")), 1) }, // 129 recreation ground
    { QBrush(QColor("#C5E677"), Qt::SolidPattern), QPen(QBrush(QColor("#C5E677")), 1) }, // 130 park
    { QBrush(QColor("#E5F697"), Qt::SolidPattern), QPen(QBrush(QColor("#A9E694")), 1) }, // 131 playground
    { QBrush(QColor("#A9E694"), Qt::SolidPattern), QPen(QBrush(QColor("#BF5BE6")), 1) }, // 132 village green
    { QBrush(QColor("#BF5BE6"), Qt::SolidPattern), QPen(QBrush(QColor("#773377")), 1) }, // 133 comercial
    { QBrush(QColor("#333377"), Qt::SolidPattern), QPen(QBrush(QColor("#333377")), 1) }, // 134 industrial
    { QBrush(QColor("#442222"), Qt::SolidPattern), QPen(QBrush(QColor("#333333")), 1) }, // 135 military
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 136
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 137
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 138
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 139
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 140
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 141
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 142
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 143
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 144
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 145
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 146
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 147
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 148
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 149
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 150
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 151
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 152
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 153
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 154
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 155
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 156
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 157
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 158
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 159
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 160
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 161
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 162
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 163
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 164
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 165
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 166
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 167
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 168
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 169
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 170
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 171
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 172
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 173
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 174
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 175
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 176
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 177
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 178
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 179
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 180
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 181
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 182
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 183
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 184
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 185
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 186
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 187
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 188
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 189
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 190
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 191
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 192
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 193
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 194
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 195
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 196
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 197
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 198
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 199
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 200
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 201
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 202
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 203
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 204
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 205
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 206
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 207
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 208
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 209
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 210
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 211
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 212
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 213
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 214
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 215
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 216
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 217
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 218
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 219
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 220
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 221
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 222
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 223
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 224
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 225
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 226
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 227
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 228
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 229
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 230
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 231
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 232
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 233
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 234
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 235
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 236
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 237
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 238
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 239
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 240
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 241
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 242
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 243
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 244
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 245
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 246
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 247
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 248
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 249
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 250
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 251
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 252
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 253
    { QBrush(QColor("#777777"), Qt::SolidPattern), QPen(QBrush(QColor("#777777")), 1) }, // 254
    { QBrush(QColor("#FF7777"), Qt::SolidPattern), QPen(QBrush(QColor("#FF7777")), 1) } // 255
};

#endif // WAYSTYLES_H
