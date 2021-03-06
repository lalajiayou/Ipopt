// Copyright (C) 2004, 2011 International Business Machines and others.
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// Authors:  Andreas Waechter, Carl Laird       IBM    2004-09-27

#ifndef __IPORIGITERATIONOUTPUT_HPP__
#define __IPORIGITERATIONOUTPUT_HPP__

#include "IpIterationOutput.hpp"

namespace Ipopt
{

/** Class for the iteration summary output for the original NLP.
 */
class OrigIterationOutput: public IterationOutput
{
public:
   /**@name Constructors / Destructor */
   //@{
   /** Default Constructor */
   OrigIterationOutput();

   /** Destructor */
   virtual ~OrigIterationOutput();
   //@}

   virtual bool InitializeImpl(
      const OptionsList& options,
      const std::string& prefix
   );

   /** Method to do all the summary output per iteration.
    *
    *  This include the one-line summary output as well as writing the
    *  details about the iterates if desired.
    */
   virtual void WriteOutput();

   /** Methods for OptionsList */
   //@{
   static void RegisterOptions(
      SmartPtr<RegisteredOptions> roptions
   );
   //@}

private:
   /**@name Default Compiler Generated Methods (Hidden to avoid
    * implicit creation/calling).
    *
    * These methods are not implemented
    * and we do not want the compiler to implement them for us, so we
    * declare them private and do not define them. This ensures that
    * they will not be implicitly created/called.
    */
   //@{
   /** Copy Constructor */
   OrigIterationOutput(
      const OrigIterationOutput&
   );

   /** Overloaded Assignment Operator */
   void operator=(
      const OrigIterationOutput&
   );
   //@}

   /** Flag indicating weather info string should be printed at end
    *  of iteration summary line.
    */
   bool print_info_string_;

   /** Option indication what should be printed in inf_pr column */
   InfPrOutput inf_pr_output_;

   /** Option indicating at which iteration frequency the summary line should be printed */
   int print_frequency_iter_;

   /** Option indicating at which time frequency the summary line should be printed */
   Number print_frequency_time_;
};

} // namespace Ipopt

#endif
