
#include <iostream>

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkGradientMagnitudeImageFilter.h"

constexpr unsigned int dimension {2};
using Pixel   = unsigned char;
using Image   = itk::Image <Pixel, dimension>;
using Reader  = itk::ImageFileReader<Image>;
using Writer  = itk::ImageFileWriter<Image>;
using Filter  = itk::GradientMagnitudeImageFilter<Image, Image>;

/*
 * Gradient Magnitude
 *
 * Read file and compute the gradient magnitude
 * of an input image file
 */
int main(int argc, char* argv[])
{

  if(argc < 2)
  {
    std::cerr << "Error, please use like this `./hello \"file1.png file2.png ... fileN.png \" " << std::endl;
    return -1;
  }

  for(decltype(argc) img = 1; img < argc; img++)
  {
    const std::string fileIn{argv[img]};
    const std::string fileOut{"out_" + fileIn};

    auto reader = Reader::New();
    auto writer = Writer::New();
    auto filter = Filter::New();

    reader->SetFileName(fileIn);
    writer->SetFileName(fileOut);

    filter->SetInput( reader->GetOutput() );
    filter->Update();

    writer->SetInput( filter->GetOutput() );
    writer->Update();
  }

  return 0;
}


