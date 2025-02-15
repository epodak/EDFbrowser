/*
***************************************************************************
*
* Author: Teunis van Beelen
*
* Copyright (C) 2012, 2013, 2014, 2015, 2016 Teunis van Beelen
*
* Email: teuniz@gmail.com
*
***************************************************************************
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
***************************************************************************
*/


#ifndef UI_RAW2EDFFORM_H
#define UI_RAW2EDFFORM_H


#include <QtGlobal>
#include <QApplication>
#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateTimeEdit>
#include <QDateTime>
#include <QString>
#include <QFileDialog>
#include <QCursor>
#include <QCheckBox>
#include <QMessageBox>
#include <QPixmap>
#include <QToolTip>
#include <QComboBox>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xml.h"
#include "utils.h"
#include "edflib.h"
#include "global.h"


  struct raw2edf_var_struct{
          int sf;
          int chns;
          int phys_max;
          int straightbinary;
          int endianness;
          int samplesize;
          int offset;
          int skipblocksize;
          int skipbytes;
          char phys_dim[16];
        };




class UI_RAW2EDFapp : public QObject
{
  Q_OBJECT

public:
  UI_RAW2EDFapp(struct raw2edf_var_struct *, char *recent_dir=NULL, char *save_dir=NULL);

private:

QDialog       *raw2edfDialog;

QLabel        *SignalsLabel,
              *OffsetLabel,
              *SamplefreqLabel,
              *PatientnameLabel,
              *RecordingLabel,
              *DatetimeLabel,
              *SampleSizeLabel,
              *skipblocksizeLabel,
              *skipbytesLabel,
              *PhysicalMaximumLabel,
              *PhysicalDimensionLabel,
              *EncodingLabel,
              *variableTypeLabel,
              *EndiannessLabel;

QLineEdit     *PatientnameLineEdit,
              *RecordingLineEdit,
              *PhysicalDimensionLineEdit;

QSpinBox      *SignalsSpinbox,
              *OffsetSpinbox,
              *SamplefreqSpinbox,
              *SampleSizeSpinbox,
              *skipblocksizeSpinbox,
              *skipbytesSpinbox,
              *PhysicalMaximumSpinbox;

QComboBox     *EncodingCombobox,
              *EndiannessCombobox;

QDateTimeEdit *StartDatetimeedit;

QPushButton   *GoButton,
              *CloseButton,
              *SaveButton,
              *LoadButton;

char *recent_opendir,
     *recent_savedir;

int edfsignals,
    offset,
    samplefrequency,
    edf_format;

struct raw2edf_var_struct *raw2edf_var;

private slots:

void gobuttonpressed();
void savebuttonpressed();
void loadbuttonpressed();
void PhysicalDimensionLineEdited(QString);
void sampleTypeChanged(int);

};




#endif


