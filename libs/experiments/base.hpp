/*
  QSTEM - image simulation for TEM/STEM/CBED
  Copyright (C) 2000-2010  Christoph Koch
  Copyright (C) 2010-2013  Christoph Koch, Michael Sarahan
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EXPERIMENT_BASE_H
#define EXPERIMENT_BASE_H

#include "experiment_interface.hpp"
#include "potential.hpp"
#include "wavefunctions.hpp"

class CExperimentBase : public IExperiment
{
public:
  CExperimentBase(const ConfigReaderPtr &configReader);
  virtual void DisplayProgress(int flag, WavePtr &wave, StructurePtr &crystal);
  virtual void Run()=0;
protected:
  virtual void SaveImages()=0;

  WavePtr m_wave;
  PotPtr m_pot;

  bool m_tds;
  unsigned m_avgRuns, m_avgCount;  // number of runs to average; runs currently averaged

  std::vector<float_tt> m_chisq;
};

#endif










