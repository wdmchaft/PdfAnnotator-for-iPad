//
//  PDFPagingViewController.h
//  PdfAnnotator
//
//  Created by Raphael Cruzeiro on 7/10/11.
//  Copyright 2011 Inspira Tecnologia e Mkt. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PDFDocument;
@class PDFThumbnailFactory;
@protocol PDFPagingViewProtocol;

@interface PDFPagingViewController : UIViewController <UIScrollViewDelegate> {
    BOOL expanded;
    CGRect expandedFrame;
    CGRect collapsedFrame;
    NSMutableArray *thumbs;
    CGFloat currentX;
}

@property (nonatomic, retain) id<PDFPagingViewProtocol> delegate;

@property (nonatomic, retain) PDFDocument *_document;

@property (nonatomic, retain) PDFThumbnailFactory *thumbFactory;

@property (nonatomic, retain) UIButton *collapseButton;

@property (nonatomic, retain) UIScrollView *scrollView;

- (id)initWithDocument:(PDFDocument*)document AndObserver:(id<PDFPagingViewProtocol>)observer;
- (void)expand;
- (void)collapse;
- (void)toggle;
- (void)loadThumbs;

- (void)pageItemClicked:(id)sender;

@end

@protocol PDFPagingViewProtocol <NSObject>

- (void)pageSelected:(NSInteger)page;

@end
