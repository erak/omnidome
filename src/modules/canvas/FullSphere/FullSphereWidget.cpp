/* Copyright (c) 2014-2015 "Omnidome" by cr8tr
 * Dome Mapping Projection Software (http://omnido.me).
 * Omnidome was created by Michael Winkelmann aka Wilston Oreo (@WilstonOreo)
 *
 * This file is part of Omnidome.
 *
 * Omnidome is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "FullSphere.h"
#include "FullSphereWidget.h"

namespace omni {
    namespace ui {
        namespace canvas {
            FullSphere::FullSphere(QWidget *_parent) : CanvasParameters(_parent) {
                setup();
            }

            FullSphere::FullSphere(omni::canvas::Interface *_canvas, QWidget *_parent) :
                CanvasParameters(_canvas, _parent) {
                setup();
            }

            FullSphere::~FullSphere() {}

            void FullSphere::updateCanvasParameters() {
                auto *_fullsphere = static_cast<omni::canvas::FullSphere *>(canvas());
                _fullsphere->setDiameter(getParamAsFloat("Diameter"));
                _fullsphere->setCenter(QVector3D(
                           getParamAsFloat("X Offset"),
                           getParamAsFloat("Y Offset"),
                           getParamAsFloat("Z Offset")));
            }

            void FullSphere::setup() {
                if (!canvas()) return;

                this->locked([&]() {
                    auto* _diameter = addOffsetWidget("Diameter",5.0,0.5,20.0);
                    auto *_xOffset = addOffsetWidget("X Offset",
                                                     0.0,
                                                     -10.0,
                                                     10.0);
                    auto *_yOffset = addOffsetWidget("Y Offset",
                                                     0.0,
                                                     -10.0,
                                                     10.0);
                    auto *_zOffset = addOffsetWidget("Z Offset",
                                                     0.0,
                                                     -10.0,
                                                     10.0);

                    /// Retrieve parameters for FullSphere canvas
                    auto* _fullsphere = static_cast<omni::canvas::FullSphere*>(canvas());
                    _diameter->setValue(_fullsphere->diameter());
                    _xOffset->setValue(_fullsphere->center().x());
                    _yOffset->setValue(_fullsphere->center().y());
                    _zOffset->setValue(_fullsphere->center().z());
                });
            }
        }
    }
}
