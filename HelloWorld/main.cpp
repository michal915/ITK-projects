
#include <iostream>

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkGradientMagnitudeImageFilter.h"

constexpr unsigned int dimension {2};
using Pixel = unsigned short;
using Image  = itk::Image <Pixel, dimension>;
using Reader = itk::ImageFileReader<Image>;
using Filter = itk::GradientMagnitudeImageFilter<Image, Image>;


/*
 * First test project using ITK library
 *
 * Read file and compute the gradient magnitude
 * of an input image file
 */
int main(int argc, char* argv[])
{
  std::cout << "Hello ITK World !" << std::endl;

  if(argc != 2)
  {
    std::cerr << "Error, please use like this `./hello \"filename.jpeg\" " << std::endl;
    return -1;
  }

  const char* filename = argv[1];

  auto reader = Reader::New();
  auto filter = Filter::New();

  reader->SetFileName(filename);
  filter->SetInput( reader->GetOutput() );
  filter->Update();

  return 0;
}

