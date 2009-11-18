/*
 * Copyright (C) 2009 Nicolas Bonnefon and other contributors
 *
 * This file is part of glogg.
 *
 * glogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glogg.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "log.h"

#include "infoline.h"

// This file implements InfoLine. It is responsible for decorating the
// widget and managing the completion gauge.

InfoLine::InfoLine() :
    QLabel(), origPalette_( palette() ),
    backgroundColor_( origPalette_.color( QPalette::Button ) ),
    darkBackgroundColor_( origPalette_.color( QPalette::Dark ) )
{
    setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::Fixed );

    setAutoFillBackground( true );
}

void InfoLine::displayGauge( int completion )
{
    int changeoverX = width() * completion / 100;

    QLinearGradient linearGrad( changeoverX - 1, 0, changeoverX + 1, 0 );
    linearGrad.setColorAt( 0, darkBackgroundColor_ );
    linearGrad.setColorAt( 1, backgroundColor_ );

    QPalette newPalette = origPalette_;
    newPalette.setBrush( backgroundRole(), QBrush( linearGrad ) );
    setPalette( newPalette );
}

void InfoLine::hideGauge()
{
    setPalette( origPalette_ );
}
