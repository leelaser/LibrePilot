/**
 ******************************************************************************
 *
 * @file       configgroundvehiclewidget.h
 * @author     The LibrePilot Project, http://www.librepilot.org Copyright (C) 2015-2016.
 *             The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup ConfigPlugin Config Plugin
 * @{
 * @brief ground vehicle configuration panel
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef CONFIGGROUNDVEHICLEWIDGET_H
#define CONFIGGROUNDVEHICLEWIDGET_H

#include "cfg_vehicletypes/vehicleconfig.h"

#include "../uavobjectwidgetutils/configtaskwidget.h"
#include "extensionsystem/pluginmanager.h"
#include "uavobjectmanager.h"
#include "uavobject.h"

class Ui_GroundConfigWidget;

class QWidget;
class QGraphicsSvgItem;

class ConfigGroundVehicleWidget : public VehicleConfig {
    Q_OBJECT

public:
    static QStringList getChannelDescriptions();

    ConfigGroundVehicleWidget(QWidget *parent = 0);
    ~ConfigGroundVehicleWidget();

    virtual void refreshWidgetsValues(QString frameType);
    virtual void initMixerCurves(QString frameType);
    virtual QString updateConfigObjectsFromWidgets();

protected:
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

    virtual void enableControls(bool enable);

private:
    Ui_GroundConfigWidget *m_aircraft;
    QGraphicsSvgItem *m_vehicleImg;

    virtual void registerWidgets(ConfigTaskWidget &parent);
    virtual void resetActuators(GUIConfigDataUnion *configData);

    bool setupGroundVehicleTurnable(QString airframeType);
    bool setupGroundVehicleDifferential(QString airframeType);
    bool setupGroundVehicleMotorcycle(QString airframeType);

private slots:
    virtual void setupUI(QString airframeType);
    virtual bool throwConfigError(QString airframeType);
};

#endif // CONFIGGROUNDVEHICLEWIDGET_H
