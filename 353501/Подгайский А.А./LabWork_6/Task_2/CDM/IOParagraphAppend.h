#ifndef FC74E9D5_D959_47CD_AD50_480B089F8657
#define FC74E9D5_D959_47CD_AD50_480B089F8657

#include "IOParagraph.h"
#include "IOService.h"
#include <qtmetamacros.h>
class IOParagraphAppend : public IOService {
  Q_OBJECT

public:
  using IOService::IOService;

  const QString FNAME = FILE_PREF + "_3.txt";

  virtual QString getInstructions() override;

  virtual void initInput() override;
  virtual void initOutput() override;

  void enterInput();

protected slots:
  virtual void processOutput() override;
};

#endif /* FC74E9D5_D959_47CD_AD50_480B089F8657 */
