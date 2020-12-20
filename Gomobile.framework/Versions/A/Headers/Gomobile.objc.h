// Objective-C API for talking to github.com/AndreasSko/go-jwlm/gomobile Go package.
//   gobind -lang=objc github.com/AndreasSko/go-jwlm/gomobile
//
// File is generated by gobind. Do not edit.

#ifndef __Gomobile_H__
#define __Gomobile_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class GomobileDatabaseStats;
@class GomobileDatabaseWrapper;
@class GomobileDownloadManager;
@class GomobileDownloadProgress;
@class GomobileMergeConflict;
@class GomobileMergeConflictError;
@class GomobileMergeConflictsWrapper;
@class GomobilePublicationLookup;

/**
 * DatabaseStats represents the rough number of entries
within a Database{} by defining it as the length
of the slices.
 */
@interface GomobileDatabaseStats : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) long blockRange;
@property (nonatomic) long bookmark;
@property (nonatomic) long location;
@property (nonatomic) long note;
@property (nonatomic) long tag;
@property (nonatomic) long tagMap;
@property (nonatomic) long userMark;
@end

/**
 * DatabaseWrapper wraps the left, right, and merged
Database structs so they can be used with Gomobile.
 */
@interface GomobileDatabaseWrapper : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * DBIsLoaded indicates if a DB on the given side has been loaded.
 */
- (BOOL)dbIsLoaded:(NSString* _Nullable)side;
/**
 * ExportMerged exports the merged database to filename.
 */
- (BOOL)exportMerged:(NSString* _Nullable)filename error:(NSError* _Nullable* _Nullable)error;
/**
 * ImportJWLBackup imports a .jwlibrary backup file into the struct
on the given side.
 */
- (BOOL)importJWLBackup:(NSString* _Nullable)filename side:(NSString* _Nullable)side error:(NSError* _Nullable* _Nullable)error;
/**
 * Init initializes the DatabaseWrapper to prepare for subsequent
function calls. Should be called after ImportJWLBackup.
 */
- (void)init_;
/**
 * MergeBookmarks merges bookmarks
 */
- (BOOL)mergeBookmarks:(NSString* _Nullable)conflictSolver mcw:(GomobileMergeConflictsWrapper* _Nullable)mcw error:(NSError* _Nullable* _Nullable)error;
/**
 * MergeLocations merges locations
 */
- (BOOL)mergeLocations:(NSError* _Nullable* _Nullable)error;
/**
 * MergeNotes merges notes
 */
- (BOOL)mergeNotes:(NSString* _Nullable)conflictSolver mcw:(GomobileMergeConflictsWrapper* _Nullable)mcw error:(NSError* _Nullable* _Nullable)error;
/**
 * MergeTagMaps merges tagMaps
 */
- (BOOL)mergeTagMaps:(NSError* _Nullable* _Nullable)error;
/**
 * MergeTags merges tags
 */
- (BOOL)mergeTags:(NSError* _Nullable* _Nullable)error;
/**
 * MergeUserMarkAndBlockRange merges UserMarks and BlockRanges
 */
- (BOOL)mergeUserMarkAndBlockRange:(NSString* _Nullable)conflictSolver mcw:(GomobileMergeConflictsWrapper* _Nullable)mcw error:(NSError* _Nullable* _Nullable)error;
/**
 * Stats generates a DatabaseStats for the given mergeSide
 */
- (GomobileDatabaseStats* _Nullable)stats:(NSString* _Nullable)side;
@end

/**
 * DownloadManager keeps all the information of a running download, enabling it
to check progress and also cancel the download if necessary
 */
@interface GomobileDownloadManager : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) GomobileDownloadProgress* _Nullable progress;
/**
 * CancelDownload cancels a running download
 */
- (void)cancelDownload;
/**
 * DownloadSuccessful indicates if the download has been successful
 */
- (BOOL)downloadSuccessful;
/**
 * Error returns possible errors of a download as a string
 */
- (NSString* _Nonnull)error;
@end

/**
 * DownloadProgress represents the progress of a running download
 */
@interface GomobileDownloadProgress : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) int64_t size;
@property (nonatomic) int64_t bytesComplete;
@property (nonatomic) double bytesPerSecond;
@property (nonatomic) double progress;
@property (nonatomic) BOOL done;
@property (nonatomic) BOOL canceled;
@end

/**
 * MergeConflict represents two Models that collide. It is equvalent
to merger.MergeConflict, but represents the Models as strings
to make it compatible with Gomobile.
 */
@interface GomobileMergeConflict : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull key;
@property (nonatomic) NSString* _Nonnull left;
@property (nonatomic) NSString* _Nonnull right;
@end

/**
 * MergeConflictError indicates that a conflict happened while merging. It
is equivalent to merger.MergeConflictError, but does not contain the
actual conflicts to make it compatible with Gomobile.
 */
@interface GomobileMergeConflictError : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull err;
- (NSString* _Nonnull)error;
@end

/**
 * MergeConflictsWrapper wraps mergeConflicts and their solutions
 */
@interface GomobileMergeConflictsWrapper : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) GomobileDatabaseWrapper* _Nullable dbWrapper;
/**
 * InitDBWrapper initializes the DatabaseWrapper for the MergeConflictsWrapper
so the DB is accessible for pretty printing.
 */
- (void)initDBWrapper:(GomobileDatabaseWrapper* _Nullable)dbw;
/**
 * NextConflict returns the next conflict that should be solved. If there
are no left, it returns an error
 */
- (GomobileMergeConflict* _Nullable)nextConflict:(NSError* _Nullable* _Nullable)error;
/**
 * SolveConflict solves a mergeConflict represented by key and chooses the given side
 */
- (BOOL)solveConflict:(NSString* _Nullable)key side:(NSString* _Nullable)side error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * PublicationLookup represents a lookup for a publication.
It directly maps to publication.Lookup
 */
@interface GomobilePublicationLookup : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) long documentID;
@property (nonatomic) NSString* _Nonnull keySymbol;
@property (nonatomic) long issueTagNumber;
@property (nonatomic) long mepsLanguage;
@end

/**
 * CatalogExists checks if catalog.db exists at path
 */
FOUNDATION_EXPORT BOOL GomobileCatalogExists(NSString* _Nullable path);

/**
 * CatalogNeedsUpdate checks if catalog.db located at path is still up-to-date.
For now it just makes sure that it is younger than one month.
If it can't find a file at path, it returns true
 */
FOUNDATION_EXPORT BOOL GomobileCatalogNeedsUpdate(NSString* _Nullable path);

/**
 * CatalogSize returns the size of the catalog.db at path
 */
FOUNDATION_EXPORT int64_t GomobileCatalogSize(NSString* _Nullable path);

/**
 * DownloadCatalog downloads the newest catalog.db and saves it at dst. The
returned DownloadManager allows to keep track and manage the running download
 */
FOUNDATION_EXPORT GomobileDownloadManager* _Nullable GomobileDownloadCatalog(NSString* _Nullable dst);

/**
 * LookupPublication looks up a publication from catalogDB located at dbPath
and returns a JSON string representing the Publication
 */
FOUNDATION_EXPORT NSString* _Nonnull GomobileLookupPublication(NSString* _Nullable dbPath, GomobilePublicationLookup* _Nullable query);

#endif
