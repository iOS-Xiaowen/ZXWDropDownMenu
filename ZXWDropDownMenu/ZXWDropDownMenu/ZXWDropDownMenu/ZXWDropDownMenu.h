//
//  ZXWDropDownMenu.h
//  ZXWDropDownMenu
//
//  Created by loongs_zxw on 17/3/12.
//  Copyright © 2017年 loongs_zxw. All rights reserved.
//

#import <UIKit/UIKit.h>
@interface ZXWIndexPath : NSObject

@property (nonatomic, assign) NSInteger column;
@property (nonatomic, assign) NSInteger leftOrRight;
@property (nonatomic, assign) NSInteger leftRow;
@property (nonatomic, assign) NSInteger row;
- (instancetype)initWithColumn:(NSInteger)column leftOrRight:(NSInteger)leftOrRight leftRow:(NSInteger)leftRow row:(NSInteger)row;
+ (instancetype)indexPathWithCol:(NSInteger)col leftOrRight:(NSInteger)leftOrRight leftRow:(NSInteger)leftRow row:(NSInteger)row;

@end


#pragma mark - data source protocol
@class ZXWDropDownMenu;

@protocol ZXWDropDownMenuDataSource <NSObject>

@required
- (NSInteger)menu:(ZXWDropDownMenu *)menu numberOfRowsInColumn:(NSInteger)column leftOrRight:(NSInteger)leftOrRight leftRow:(NSInteger)leftRow;
- (NSString *)menu:(ZXWDropDownMenu *)menu titleForRowAtIndexPath:(ZXWIndexPath *)indexPath;
- (NSString *)menu:(ZXWDropDownMenu *)menu titleForColumn:(NSInteger)column;
/**
 * 表视图显示时，左边表显示比例
 */
- (CGFloat)widthRatioOfLeftColumn:(NSInteger)column;
/**
 * 表视图显示时，是否需要两个表显示
 */
- (BOOL)haveRightTableViewInColumn:(NSInteger)column;

/**
 * 返回当前菜单左边表选中行
 */
- (NSInteger)currentLeftSelectedRow:(NSInteger)column;

@optional
//default value is 1
- (NSInteger)numberOfColumnsInMenu:(ZXWDropDownMenu *)menu;

/**
 * 是否需要显示为UICollectionView 默认为否
 */
- (BOOL)displayByCollectionViewInColumn:(NSInteger)column;

@end



#pragma mark - delegate
@protocol ZXWDropDownMenuDelegate <NSObject>
@optional
- (void)menu:(ZXWDropDownMenu *)menu didSelectRowAtIndexPath:(ZXWIndexPath *)indexPath;
@end

#pragma mark - interface
@interface ZXWDropDownMenu : UIView <UITableViewDataSource, UITableViewDelegate, UICollectionViewDataSource, UICollectionViewDelegate,UICollectionViewDelegateFlowLayout>

@property (nonatomic, weak) id <ZXWDropDownMenuDataSource> dataSource;
@property (nonatomic, weak) id <ZXWDropDownMenuDelegate> delegate;

@property (nonatomic, strong) UIColor *indicatorColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *separatorColor;
/**
 *  the width of menu will be set to screen width defaultly
 *
 *  @param origin the origin of this view's frame
 *  @param height menu's height
 *
 *  @return menu
 */
- (instancetype)initWithOrigin:(CGPoint)origin andHeight:(CGFloat)height;
- (NSString *)titleForRowAtIndexPath:(ZXWIndexPath *)indexPath;

@end
